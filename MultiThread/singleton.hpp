#pragma once

#include <algorithm>
#include <functional>
#include <memory>
#include <mutex>
#include <utility>
#include <vector>

class SingletonFinalizer final
{
    SingletonFinalizer() = delete;
    static inline std::vector<std::function<void()>> finalizers;

   public:
    static void addFinalizer(std::function<void()>&& func)
    {
        finalizers.emplace_back(std::forward<decltype(func)>(func));
    }
    static void finalize() noexcept
    {
        std::for_each(finalizers.crbegin(), finalizers.crend(), [](auto&& fn) {
            fn();
        }),
            finalizers.clear();
    }
};

template <typename T>
class SingletonImpl final
{
    SingletonImpl() = delete;
    static inline std::once_flag     init_flag;
    static inline std::unique_ptr<T> instance;
    template <typename... Args>
    static void create(Args&&... args)
    {
        instance = std::make_unique<T>(std::forward<Args>(args)...);
        SingletonFinalizer::addFinalizer([] { instance.reset(nullptr); });
    }

   public:
    template <typename... Args>
    static T& getIncetance(Args&&... args)
    {
        std::call_once(init_flag, create<Args...>, std::forward<Args>(args)...);
        return *instance.get();
    }
};

class Singleton final
{
    Singleton() = delete;

   public:
    template <typename T, typename... Args>
    static T& getIncetance(Args&&... args)
    {
        return SingletonImpl<T>::getIncetance(std::forward<Args>(args)...);
    }
    static void finalize() noexcept
    {
        SingletonFinalizer::finalize();
    }
};
