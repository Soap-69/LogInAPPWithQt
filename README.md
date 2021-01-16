# LogInAPPWithQt
This app is based on Qt and will allow customer and user to use and manage inventory 
Windows Qt & C++17 based program.


***For customer user use only:
When you are on the login page. It is good to notice that you might log in as a guest and also
checkout as a guest, by the time you pick up your vehicle. Staff will record your name and other
information. So it is not necessary to enter user name and password. However, this feature can
be implemented in the future so our customer would be able to register and create their own
profile online.
As you click log in, a shopping page will be available to you and first thing first you need to
check the availability of this vehicle. Notice that our admin will resupply those vehicles as soon
as possible. After you click “Check availability”, the vehicle with 0 stock will disappear and you
can shop the rest of the vehicles by clicking on the checkbox. Whenever you are done with
shopping, you are free to checkout by clicking the “Checkout” button. Then the total amount you
should pay before ordering the car includes tax on the screen. You may not purchase two cars
with the same type at once as you will need to check whether that type is available or not. If you
want to purchase two same vehicles, you might want to checkout and quit, then log in again to
make another order! :D


***For Admin user use only:
The username and password are unique with customer log in, the username is “admin” and the
password is “1234”. While you successfully log into the admin page, stock is not available
warning will pop out if the stock of a specific vehicle is 0. On the left upper corner, there are
three options available. “Tally Monthly sales total” will calculate your monthly sales total and.
“Tally total taxes” will calculate how much tax people paid during their purchase. “Tally monthly
sales per item” will pop out a window which lists how many sales per item this month.
On the right upper corner is the place you can manage your inventory, as you click that button, it
will bring you to the database management window. *!!!ATTENTION!!!*. The database is based
on file and if you want to view current inventory, click “Current Inventory” and the current stock
and customer include order ID and price will show on the screen. The order with order ID “0000”
is the price tag for each vehicle, then it’s the vehicle name, after that is the price for that vehicle,
finally those numbers are how many stock remaining on your dealership. Starting with order ID
“0001” are customer records, first is customer order ID, next is which type of vehicle they
purchased, then is how much they paid to get their vehicle, after that is the name of the
customer. You are free to change those information but have to follow the format
(“OrderID:Vehicle type:Sales price:Customer name”). Whenever you are done, be sure to click
the “Update Inventory” button and that will update what you have changed, otherwise it won’t be
saved(make sure to decrease the amount of stock after the customer makes a purchase).
!!!ATTENTION!!! Be sure to clean the customer's record and move to another file in order to
calculate monthly sales and sales per item. Another button allows the admin to list customers
from high to low.
On the bottom side of the admin page, you can search for specific orders either by customer
name or by order ID. It is pretty straightforward, just click which type you want to search and
enter the order ID or customer name. Then click ok or hit enter to get the result. Whenever you
want to quit, just hit the quit button on the right bottom side and you can quit the application.



***For developer:
This program created some classes which can be used for further functions development, for
example on MainWindow.cpp there are two functions called void MainWindow::pressKey(int
Key){}; and void MainWindow::pressKey(QString register){}; . Those two functions can be
implemented into one button. Whenever a user clicks, depending on whether the user has an
account or not on file. The system will automatically bring the user to the register page or log in
page. *Don’t forget to also add those functions into the header file as comments show on
MainWindow.h. As long as the program works, you can add more functions and reach your
development goals.
