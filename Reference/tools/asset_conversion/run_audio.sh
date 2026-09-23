#!/bin/bash
S=/tmp/claude-0/-home-claude/a1a35670-f1fc-5e95-96f0-922d382f67cc/scratchpad
D=$S/obbdata/47947_GOF2CONTENT_ETC/assets/data/audio
OUT=$S/unitypkg/Assets/GoF2/Audio
TMP=$S/audiotmp
for f in $D/*.fsb; do
  bank=$(basename $f .fsb | sed 's/^FMOD_GOF2_\?//'); [ -z "$bank" ] && bank=MAIN
  mkdir -p $TMP/$bank $OUT/$bank
  $S/vgm/vgmstream-cli -S 0 -o "$TMP/$bank/?n.wav" "$f" > /dev/null 2>&1
  for w in $TMP/$bank/*.wav; do
    n=$(basename "$w" .wav)
    ffmpeg -nostdin -loglevel error -y -i "$w" -c:a libvorbis -q:a 5 "$OUT/$bank/$n.ogg" && rm "$w"
  done
  echo "$bank $(ls $OUT/$bank | wc -l)"
done
cp $D/FMOD_GOF2.fev $OUT/_FMOD_GOF2.fev.bytes
echo AUDIO_DONE
