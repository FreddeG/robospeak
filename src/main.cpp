#include "ros/ros.h"
#include <std_msgs/String.h>
#include <sound_play/sound_play.h>
#include <unistd.h>
#include <sound_play/SoundRequest.h>
#include "rossoundtest/sayString.h"

sound_play::SoundClient *ptr;

bool toSay(rossoundtest::sayString::Request  &req,
         rossoundtest::sayString::Response &res)
{
	ROS_INFO("request: %s", req.str.c_str());
	res.str.assign(req.str);
    ptr->say(req.str.c_str());
    sleep(2); // should base on character length
	return true;

	/*
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
  */
}


void sleepok(int t, ros::NodeHandle &nh) // dunno from sample code, no idea what .ok does
{
  if (nh.ok())
      sleep(t);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sound_play_test");

  ros::NodeHandle nh;
  sound_play::SoundClient sc;
  ptr = &sc;
  sleepok(2, nh);
  sc.say("Hello world!");
  sleepok(2, nh);
  ros::ServiceServer service = nh.advertiseService("say_string", toSay);
  ROS_INFO("Ready to listen");
  ros::spin();

  /*
  while(nh.ok())
  {
    sc.say("Hello world!");
    sleepok(2, nh);
    sc.say("Does this work?");
    sleepok(2, nh);
    sc.say("This took too long to fix, fucking sleepok is retarded");
    sleepok(5, nh);
    //sc.say(argv[2]);
    sleepok(5, nh);
  	

  	
    sc.say("Hello world!");
    sleepok(2, nh);
    quiet_sc.say("Hello world!");
    sleepok(2, nh);

    const char *str1 = "I am annoying.";
    sc.repeat(str1);
    sleepok(4, nh);
    sc.stopSaying(str1);
    quiet_sc.repeat(str1);
    sleepok(4, nh);
    quiet_sc.stopSaying(str1);

    sc.playWave("/usr/share/xemacs21/xemacs-packages/etc/sounds/boing.wav");
    sleepok(2, nh);
    quiet_sc.playWave("/usr/share/xemacs21/xemacs-packages/etc/sounds/boing.wav");
    sleepok(2, nh);

    const char *str2 = "/usr/share/xemacs21/xemacs-packages/etc/sounds/piano-beep.wav";
    sc.startWave(str2);
    sleepok(4, nh);
    sc.stopWave(str2);
    quiet_sc.startWave(str2);
    sleepok(4, nh);
    quiet_sc.stopWave(str2);

    sc.play(sound_play::SoundRequest::NEEDS_UNPLUGGING);
    sleepok(2, nh);
    quiet_sc.play(sound_play::SoundRequest::NEEDS_UNPLUGGING);
    sleepok(2, nh);

    sc.play(sound_play::SoundRequest::NEEDS_UNPLUGGING);
    sleepok(2, nh);
    quiet_sc.play(sound_play::SoundRequest::NEEDS_UNPLUGGING);
    sleepok(2, nh);

    sc.start(sound_play::SoundRequest::BACKINGUP);
    sleepok(4, nh);
    sc.stop(sound_play::SoundRequest::BACKINGUP);
    quiet_sc.start(sound_play::SoundRequest::BACKINGUP);
    sleepok(4, nh);
    quiet_sc.stop(sound_play::SoundRequest::BACKINGUP);

    sleepok(2, nh);
    sound_play::Sound s1 = sc.waveSound("/usr/share/xemacs21/xemacs-packages/etc/sounds/boing.wav");
    s1.repeat();
    sleepok(1, nh);
    s1.stop();

    sleepok(2, nh);
    sound_play::Sound s2 = quiet_sc.waveSound("/usr/share/xemacs21/xemacs-packages/etc/sounds/boing.wav");
    s2.repeat();
    sleepok(1, nh);
    s2.stop();
		
    sleepok(2, nh);
    sound_play::Sound s3 = sc.voiceSound("This is a really long sentence that will get cut off.");
    s3.play();
    sleepok(1, nh);
    s3.stop();

    sleepok(2, nh);
    sound_play::Sound s4 = quiet_sc.voiceSound("This is a really long sentence that will get cut off.");
    s4.play();
    sleepok(1, nh);
    s4.stop();

    sleepok(2, nh);
    sound_play::Sound s5 = sc.builtinSound(sound_play::SoundRequest::NEEDS_UNPLUGGING_BADLY);
    s5.play();
    sleepok(1, nh);
    s5.stop();

    sleepok(2, nh);
    sound_play::Sound s6 = quiet_sc.builtinSound(sound_play::SoundRequest::NEEDS_UNPLUGGING_BADLY);
    s6.play();
    sleepok(1, nh);
    s6.stop();

    sleepok(2, nh);
    sound_play::Sound s7 = sc.waveSoundFromPkg("sound_play", "sounds/BACKINGUP.ogg");
    s7.play();
    sleepok(1, nh);
    s7.stop();

    sleepok(2, nh);
    sound_play::Sound s8 = quiet_sc.waveSoundFromPkg("sound_play", "sounds/BACKINGUP.ogg");
    s8.play();
    sleepok(1, nh);
    s8.stop();
    
   
  }
  */
}