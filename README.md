# Electric-bike
Throttle controll with arduino

# Allan Gamal

  <h2>Electric bike build</h2>
  <p>Sharing some of the process of the making of this project/p>

  <h2>Project</h3>
    <p>Making a an electric bike. 
</p>

   <h2>Thoughts and goals going into the project</h3>
     <ul>
        <li>Make an electric bike</li>
        <li>Use as much 3d printed parts as possible</li>
        <li>Make it reliable for evry day use</li>

</ul>

  <h2>Recognizing some potential issues</h2>
    <ul>
        <li>Heat management, since pla/petg is used</li>
        <li>Making it legal to use as a bike(not moped/mc)</li>
        <li>Fitting every part needed on the bike</li>
        <li>Make everything rainproof</li>
   </ul>
---

<h3>Hardware/materials</h3>
    <ul>
        <li>Turnigy CA80 160kv Brushless Outrunner</li>
        <li>Stepper motor driver ULN2003</li>
        <li>Trampa VESC 6 MkV </li>
        <li>Arduino</li>
        <li>50V 16ah lipo</li>
        <li>3d printing materials and bearings</li>
   </ul>

<img src="/imgs/ba.jpg" height="800px">
V0.1 vs VFinal

**Lets start**

I needed a cheaper transportation to school, so why not build an electric bike.

I do have a lot of hills where I live, so torque was a prio, there fore my choise of motor. To get as much torque as possible, gear ration from drive to wheel needed to be as big as possible. So I printed a 182 teeth pulley, which was the largest possible size my printer allowed. Total gear ratio is 182:16, or 91:8. I could use less teeth on the pulley to increase the torque, but that made less teeth engage with the belt, and resulted in skipping. 16 teeth is stable even at max throttle. 

I did not want to use the bike spokes to mount the pulley, since they are very thin and a lot of torque is generated. There for I use the disc (for disc break) to mount the pulley, but results in removing the back breaks, which is not optimal. I probably could have made it work if I had access to a cnc router for metal use.   

<img src="/imgs/pully.jpg" height="800px">


For every version of the bike, I noticed the motor got way to hot for my liking, and for every iteration I increased the ventilation holes and added a fan that is mounted on the motor, and not it is on an accepteble level, even on the hottest days. I was afraid the the integrity of the plastic (petg) would not hold up since I used so many ventilation holes, but it has held up with no sign of failing, surprisingly good. All the ventilation holes was printed in a as steep angles the printer allowed to ensure minimal rain is coming through. I also added a drain hole if it would for some reason fill up, but I have not seen any sign of water entering. Great!

<img src="/imgs/fan.jpg" height="800px">

Electronic box is mounted below the seat, with a sheet of rubber is integrated between the box and its lid. I have not noticed any problem with the electronics even in the heaviest rain. Inside the electronic box is the VESC and arduino.

<img src="/imgs/box.jpg" height="800px">

According to the EU laws on electric bikes, an electric bike is only legal when you are getting electric assistans when you are pedaling. My solution for this was adding magnets at the pedal, where a hall-sensor (connected to the arduino) sense the the use of the pedal/magnets, which in turn activates the thumb throttle at the stearing handle. So the thumb throttle only works if you are pedaling. 

<img src="/imgs/magnet.jpg" height="800px">



**Result**

I'm fairly happy with the results. The bike does get me 40+km every day, even in the rain. It climbs well, is very silent. 
It is very reliable in every way but one. I had to use a belt tensioner for the belt, but since it is only mounted on one axis, it is 
impossible to to mount it exactly straight, which result slow wear and tear on the belt. I know this because I always can see more wear one side than another. This results in changeing the belt every 2-3 monthm which isnt too bad, but I would like it more reliable. 

<img src="/imgs/tens.jpg" height="800px">

I do have an idea to fix this, but that would require me to redesign everything but the pulley, which would take a lot of focused time, which I at this point do not have to spare. Maybe in the future I will revisit this idea. 

Here is some images:



<img src="/imgs/final.jpg" height="800px">

