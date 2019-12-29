#!/bin/sh

#make

# for i in `seq -f %06g 0 999`
#  do
#   convert -font "./font/CENTURY.TTF" -size 200x20 -fill "#000000" -background white -pointsize 15 caption:"timestep="$i ./png/fontimage${i}.png
#  done

# ffmpeg -r 120 -i ./ppm/timestep%06d.ppm -q 0 -s 290x300 timestep.avi

# ffmpeg -r 120 -i ./png/fontimage%06d.png -q 0 -s 200x20 fontimage.avi

# ffmpeg -i timestep.avi -i fontimage.avi -filter_complex "overlay=x=0:y=0"  output.avi

#make clean
python3 ./wave_animation.py
python3 ./heatmap_animation.py
python3 ./image_paste.py
ffmpeg -i ./animation/gousei.gif -q 0 -movflags faststart -pix_fmt yuv420p -vf "scale=trunc(iw/2)*2:trunc(ih/2)*2" ./animation/output.avi

# rm ./png/*.png

# rm ./ppm/*.ppm
# rm ./png/*.png
# rm ./timestep.avi
# rm ./fontimage.avi
# ffmpeg -i gousei.gif  -movflags faststart -pix_fmt yuv420p -vf "scale=trunc(iw/2)*2:trunc(ih/2)*2" output.mp4
