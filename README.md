# Nume-de-cod-Monstri-si-lei
This is one of the projects I did during my undergraduate years. Its purpose is to cover all of the main concepts of OOP, while making a program that can help the producers of "Wednesday" see how expensive filming the second season in Romania would be. This application has helped me deepen my OOP knowledge, since the tasks required an analytical mindset and a good understanding of the main concepts of OOP. Below you can see the tasks and their constraints:

Given the success of Wednesday, the producers of the series decided to film the next season in Romania. They need a program to help them organize their project, filming and budgets. 

All these people will be found in a CSV file that will be uploaded to the application. The cast can be found online (example: https://www.imdb.com/title/tt13443470/fullcredits/?ref_=tt_cl_sm )
The file must include the name of the person and the function he/she performs (actor, sound artist, etc.). The director also decided that he needed 132 more extras to help with the filming. They will be randomly created inside the application.

All the actors and all the other people involved in the film will leave the airport using buses. Buses have a capacity of 50 people. Calculate how many buses are needed to transport people from the airport to the castle. The cost of renting a bus is 5680 lei.

Also, the actors and figurants are randomly assigned to one of the 5 monster classes, each with a specific cost for makeup per day of shooting:

- Vampires - 230 lei.  

- Werewolves - 555 lei.

- Sirens - 345 lei. 

- Clairvoyants - 157 lei.

- Humans - 55 lei.

During filming, these people must be provided with food at lunch break. Each person is either: 

- Able to eat anything. 

- Vegetarian.

- Flexitarian (eating fish). 
 
People are assigned a type of diet at random.

The application must create a 3-day menu that includes:
- Soup. 

- Main course. 

- Dessert.

The menu for those who eat anything costs 40 lei per person per day, the one for vegetarians 33 lei per person per day and the one for flexitarians 46 lei per person per day.

At the end of the day, people have to go to the hotel to sleep. The hotel has rooms of 2 and 3 people.. Rooms for 2 people are reserved for the initial stay. Cost per room per night = 350 lei. Rooms for 3 people are reserved for figurants. Cost per room per night = 420 lei

Water is also required for filming. Every day of filming is consumed on average:

- 1L of water per person.

- 0.5 L of coffee per person. 

- 0.8 L of juice per person

The cost is as follows: 2L water = 6 Lei, 1L coffee = 30 Lei, 2L juice = 8 lei. 

The rental of Cantacuzino Castle is 10000 lei per day. The owner is willing to make a 2% discount for every 10 days of filming.

At the end of the filming, all the people will return with the same buses to the airport.

The director and the producers have not yet decided whether to film in Romania. And if so, how many days should the filming take? They will make a decision based on costs. So they want to know how much it would cost if they stayed in Romania:
-	30 days
-	45 days
-	60 days
-	100 days

The cost must be expressed in dollars. The director wants to receive all the information in a CSV file.

The application must generate CSV files in which it has the following information:. 

- Actors, extended cast and figurants (1 CSV). 

- Cost per period (1 CSV). Here the costs must be grouped as follows: 

- Transport

-	Accommodation. 

- Makeup. 
 
- Food and water. 

- Renting space. 

- Food menu (1CSV)

