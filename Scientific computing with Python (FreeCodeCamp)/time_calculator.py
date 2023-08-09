def add_time(start, duration, day= None):
    import re
    later = 0
    first = re.split(r' ', start)
    time = first[0]
    half = first[1]
    first = re.split(r':', time)
    second = re.split(r':', duration)
    hour = int(first[0])
    min = int(first[1])
    dur_h = int(second[0])
    dur_m = int(second[1])
    del first
    del second
    hour = hour + dur_h
    min = min + dur_m

    if min > 60:
        min = min - 60
        hour = hour + 1
    while hour > 12:
        hour = hour - 12
        if half == 'AM':
            half = 'PM'
        elif half == 'PM':
            half = 'AM'
            try:
                if day.lower() == 'monday':
                    day = 'Tuesday'
                elif day.lower() == 'tuesday':
                    day = 'Wednesday'
                elif day.lower() == 'wednesday':
                    day = 'Thursday'
                elif day.lower() == 'thursday':
                    day = 'Friday'
                elif day.lower() == 'friday':
                    day = 'Saturday'
                elif day.lower() == 'saturday':
                    day = 'Sunday'
                elif day.lower() == 'sunday':
                    day = 'Monday'
            except:
                pass
            later = later + 1
    if hour == 12 and duration != 0:
        if half == 'AM':
            half = 'PM'
        elif half == 'PM':
            half = 'AM'
            try:
                if day.lower() == 'monday':
                    day = 'Tuesday'
                elif day.lower() == 'tuesday':
                    day = 'Wednesday'
                elif day.lower() == 'wednesday':
                    day = 'Thursday'
                elif day.lower() == 'thursday':
                    day = 'Friday'
                elif day.lower() == 'friday':
                    day = 'Saturday'
                elif day.lower() == 'saturday':
                    day = 'Sunday'
                elif day.lower() == 'sunday':
                    day = 'Monday'
            except:
                pass
            later = later + 1
    try:
        day = day.capitalize()
    except:
        pass
    min = str(min)
    if len(min) == 1:
        min = '0' + min

    try:
        if later == 0:
            new_time = str(hour) + ':' + min + ' ' + half + ', ' + day
        elif later == 1:
            new_time = str(hour) + ':' + min + ' ' + half + ', ' + day + ' (next day)'
        elif later > 1:
            new_time = str(hour) + ':' + min + ' ' + half + ', ' + day + ' (' + str(later) + ' days later)'
    except:
        if later == 0:
            new_time = str(hour) + ':' + min + ' ' + half
        elif later == 1:
            new_time = str(hour) + ':' + min + ' ' + half + ' (next day)'
        elif later > 1:
            new_time = str(hour) + ':' + min + ' ' + half + ' (' + str(later) + ' days later)'
    return new_time
