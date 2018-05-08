#include "ros/ros.h"
#include <std_msgs/String.h>
#include <sound_play/sound_play.h>
#include <unistd.h>
#include <sound_play/SoundRequest.h>


/* WHY NOT WORK??
int main(int argc, char ** argv) {
    ros::init(argc, argv, "sound_play_test");

    ros::NodeHandle nh;
    sound_play::SoundClient sc;

    sc.say("test");


    //sc.playWaveFromPkg("sound_play", "sounds/BACKINGUP.ogg");

    ros::spin();
}
*/

void sleepok(int t, ros::NodeHandle &nh)
{
  if (nh.ok())
      sleep(t);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sound_play_test");

  ros::NodeHandle nh;
  sound_play::SoundClient sc;
  sound_play::SoundClient quiet_sc;
  //sc.say("Hello world!");
  //sleep(1000);
  sleepok(1, nh);
  
  while(nh.ok())
  {
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
}