# MultiThread  
・Linux上でCPUコアを占有してスレッド処理するサンプルプログラムである。  
・必ず１スレッドに１コアを占有させる。  
・但し、実行ターゲット上のCPUコア数を超えるスレッド数で実行する場合は、１コアを複数スレッドが共用する。  
・スレッド生成にはSTLを使用しスレッドクラスを作成してその中でスレッド生成する。  
・生成した各スレッドは相互にスレッドセーフを実現していることとする。  
・複数生成したスレッド群がジョブの１単位とする。  
・処理させたいスレッドは個々にクラス生成してそのクラスの中にスレッド関数をstatic関数で作成するようにする。  
・ファイル構成はmain関数、スレッドクラス、スレッドワーカークラスのようにしておく。（実践的サンプルになるように）  
===課題===  
各スレッドワーカークラスのスレッド関数は引数にスレッドクラスのmutexインスタンスのポインタを取る必要がある。  
トライ１．スレッドクラスの派生クラスとしてスレッドワーカークラスを作成するようにする。  
トライ２．スレッド関数をラムダ式で各スレッドワーカークラスのヘッダファイル中に関数コードを実装するようにする。（既に実験済み---OK）  
