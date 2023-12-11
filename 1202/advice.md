
- Intだとovfすることあり -> long longを使用する
- 計算量がまずいので、sortしたうえで、自分のアルゴリズムを適用
- Coutの最後が “ “ + endlだと、failする（ACにならない）ことあり => 
- Loopの初めに “ “を受ける。

Ovfや時間切れ（計算量的に多すぎる）と、TLE time limitation errorになる。
- おおむね　10^8 ~ 10^9　ぐらいが計算できる計算量の上限