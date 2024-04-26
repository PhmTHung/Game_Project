# Game SURVIVOR
### Tác giả:Phạm Thế Hùng K68 J
### Trường Đại học Công Nghệ - ĐHQG Hà Nội
## Mục lục
* [Giới thiệu game](#giới-thiệu-game).
* [Cách Tải Game](#cách-tải-game).
* [Bắt đầu Game](#bắt-đầu-game).
* [Các thành phần trong game](#các-thành-phần-trong-game).
* [Cách chơi](#cách-chơi).
* [Hình ảnh](#hình-ảnh).
* [Demo game giải thích cấu trúc game](#demo-game-giải-thích-cấu-trúc-game).
* [Các kỹ thuật áp dụng để làm game](#các-kỹ-thuật-áp-dụng-để-làm-game).
* [Các tài liệu tham khảo](#các-tài-liệu-tham-khảo)
* [Nguồn tài nguyên](#nguồn-tài-nguyên)
* [Định hướng phát triển](#định-hướng-phát-triển)

# Giới thiệu game
Người chơi sẽ phải tìm cách tránh xa những con quái và viên đạn của chúng trong khi cố gắng tồn tại càng lâu càng tốt.
Trong hành trình của bạn, bạn sẽ phải thu thập vật phẩm để tăng khả năng sinh tồn của bản thân.
Với âm nhạc mạnh mẽ và đồ họa sống động, game nhập vai hành động kịch tính chắc chắn sẽ là một trải nghiệm đầy kịch tính và hấp dẫn cho người chơi.
Bạn có thể sống sót được bao lâu trong thế giới đầy thách thức này ? Điều đó là điều mà chỉ có thời gian và kỹ năng chơi của bạn mới có thể trả lời được !

# Cách Tải Game
## 1.Cách tải không bao gồm code
Ấn vào đường dẫn này [https://github.com/PhmTHung/Game_project/releases/tag/release].

Chọn vào SURVIVOR.zip và download.
![Screenshot 2024-04-26 202213](https://github.com/PhmTHung/Game_project/assets/161602413/e63e7b00-2641-40aa-a2f6-7cdf995567b5)

Chọn vào tệp zip vừa được download , giải nén tệp.

![Screenshot 2024-04-26 202654](https://github.com/PhmTHung/Game_project/assets/161602413/aa899a41-eb27-47ce-9526-9b8eb83dd065).

Ta sẽ có file như này, chọn vào file có đuôi .exe như này

![Screenshot 2024-04-26 203014](https://github.com/PhmTHung/Game_project/assets/161602413/28d25e9f-c2a2-4073-b6fc-d644a1288070)
## 2. Bao gồm code và có thể biên dịch
* Bước 1 Vào link github [https://github.com/PhmTHung/Game_project] và copy đường dẫn .
![Screenshot 2024-04-26 204307](https://github.com/PhmTHung/Game_project/assets/161602413/fcdb3c27-379a-404f-8b1f-9c3815b63ded)

* Tạo file mới trên máy tính ,mở cmd bằng cách ấn Window+R hoặc sử dụng gitbash (nếu đã cài đặt)
![Screenshot 2024-04-26 204713](https://github.com/PhmTHung/Game_project/assets/161602413/29cceb3a-908b-4588-8786-ba3cabb25a4b)

sau khi code được clone, chạy file Surivivor.cbp.
Game giờ đã có thể chạy được rồi ,chức mọi người có trải nghiệm thật vui vẻ !

# Bắt đầu Game

Ấn vào nút Play Game để bắt đầu.
![Screenshot 2024-04-26 192013](https://github.com/PhmTHung/Game_project/assets/161602413/ec35831c-bf5f-4211-80c5-b3454ab7a89f)

# Các thành phần trong game
* Drop Item: Nhặt những vật phẩm có thể giúp bạn sinh tồn lâu hơn
   * Túi máu : Giúp bạn hồi tối đa 200 HP ,hãy sử dụng chúng một cách thông minh bởi lượng máu
               được hồi phụ thuộc vào số máu bạn đã mất.

![Screenshot 2024-04-26 211210](https://github.com/PhmTHung/Game_project/assets/161602413/302ca942-b0d8-48d5-9b0f-e4a202aa3525)

   * Đồng xu : Thứ quý giá luôn được bảo vệ bởi những kẻ máu mặt ,chúng sẵn sàn tấn công bạn để
               bảo vệ những đồng tiền cổ.
     
![Screenshot 2024-04-26 211534](https://github.com/PhmTHung/Game_project/assets/161602413/c2912ab1-721f-402b-b89a-5c612aa4add6)


   * Nấm     : Được coi là sinh vật đặc biệt trên hòn đảo, ăn được chúng giúp ta cải thiện tốc
               độ chạy rất nhiều.(mỗi lần ăn nấm tốc độ chạy tăng 5%).

![Screenshot 2024-04-26 211356](https://github.com/PhmTHung/Game_project/assets/161602413/84128995-32be-4d8e-8b8d-b6b82be44811)

* Kẻ địch 1 : Những con dơi có khả năng tấn công tầm xa và cả tầm gần , chú ý giữ khoảng cách với chúng !
  
![Screenshot 2024-04-26 210450](https://github.com/PhmTHung/Game_project/assets/161602413/2311dc32-bbb0-4249-b034-47049eb712dc)


* Kẻ địch 2 : Những con rắn khổng lồ với thân hình to lớn tuy không có thể tấn công tần xa nhưng chúng có tốc độ di chuyển nhanh và lượng máu khổng lồ , tránh giao tranh với chúng để bảo toàn mạng sống !
  
![Screenshot 2024-04-26 210306](https://github.com/PhmTHung/Game_project/assets/161602413/7342797e-52ec-475e-8d7d-3a5d68e04eca)

# Cách chơi
* Điều khiển nhân vật : Sử dụng phím A->phải ,W->lên ,S->xuống ,D->phải, Space-> bắn.
* Sử dụng các phím điều khiển để nhặt các đồ vật xuất hiện trên bản đồ, tránh các mối đe doạ.
* Logic :
  * Sinh tồn lâu nhất với các vật phẩm hỗ trợ;
  * Các kẻ địch luôn luôn di chuyển tấn công chủ động nhân vật chính, lựa chọn tấn công hoặc
  bỏ chạy.
  * Mẹo :do kẻ địch xuất hiện trong một khoảng thời gian sau mỗi đợt tấn công, cố gắng nhặt những item để giúp có thể đạt được lợi thế.
# Hình ảnh
![game](https://github.com/PhmTHung/Game_project/assets/161602413/ea208a78-b2ea-4211-afb6-6bf7c80a49f9)
![Screenshot 2024-04-26 154438](https://github.com/PhmTHung/Game_project/assets/161602413/9bcfb475-0d4c-4bf3-9156-2a9e197c5427)
![Screenshot 2024-04-26 171439](https://github.com/PhmTHung/Game_project/assets/161602413/20e06c58-4efa-47bd-8c40-8a2ccc2c6bcf)

# Demo game giải thích cấu trúc game
[https://www.youtube.com/watch?v=KfGUkZPmv28]

# Các kỹ thuật áp dụng để làm game
* Kỹ thuật lập trình hướng đối tượng.
* Kỹ thuật tiled map (tham khảo LazyFoo,Let's Make Game,Phát Triển Phẩn Mềm 123az).
* Các kỹ thuật được đề cập trong Website LazyFoo.
  * Xử lý bàn phím, chuột.
  * Load ảnh, chữ ,âm thanh .
  * Hiển thị ảnh động.
  * Tính toán khung hình.
# Các tài liệu tham khảo
* Youtube :Cô Trần Thị Minh Châu.

   *[https://www.youtube.com/watch?v=f23xRQoqUu0&list=PL-IbDGFpCvtluDVQSSslFYzFueSbjDvZO&index=21]
  
* Youtube,Website: Phát Triển Phẩn Mềm 123az.

   *[https://www.youtube.com/@PhatTrienPhanMem123AZ]
  
   *[https://phattrienphanmem123az.com/]
  
* YouTube :Let's Make Game.
  
   *[https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx]

* Website : LazyFoo.

   *[https://lazyfoo.net/tutorials/SDL/]

# Nguồn tài nguyên
* Ảnh Sprite nhân vật, Tile Map:Open Game Art [https://opengameart.org/].
* Âm Thanh :Open Game Art, YouTube, các công cụ hỗ trợ để chuyển file thành file .WAV.
* Công cụ xử lý hình ảnh Aseprite.

# Định hướng phát triển
*  Nâng cấp hình ảnh 3D ,âm thanh sống động, chân thực.
*  Sử dụng các công cụ tạo các item có thể sử dụng trên người nhân vật (ngoại trang,...).
*  Chơi được trên cả điện thoại, máy tính.
*  Xây dựng serve game nhiều người chơi, tương tác, đối kháng giữa các nhân vật.
*  Mở rộng nhiều tính năng trong trò chơi (mua bán vật phẩm,định giá vật phẩm, trao đổi vật phẩm giữa các người chơi)
*  Có thể đưa lên các trang phát hành game.


