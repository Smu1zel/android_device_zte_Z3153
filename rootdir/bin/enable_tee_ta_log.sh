#!/vendor/bin/sh

# use setlog -u ta_name to enable ta log
function enable_teeos_and_ta_log()
{
    echo "enable fingerprint ta_log"
    local fp=`getprop vendor.fingerprint.id`
    echo "$fp"
    if [[ $fp == "gf3658" ]];then
        setlog -u 7b30b820-a9ea-11e5-b1780002a5d5c51b  -l 3
        setlog -u 7b30b820-a9ea-11e5-b1780002a5d5c51b  -l 3  -t
    elif [[ $fp == "silead" ]];then
        setlog -u a8224991-8c4f-42fc-8cbe623821ecc211  -l 3
        setlog -u a8224991-8c4f-42fc-8cbe623821ecc211  -l 3  -t
    else
        echo "unsupport_fingerprint"
    fi
}

enable_teeos_and_ta_log

