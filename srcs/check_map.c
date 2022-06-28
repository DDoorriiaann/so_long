#include"so_long.h"

t_error check_borders(t_data *data, t_map_check *counters)
{
    if (counters->y == 0 || counters->y == data->h_res - 1)
    {   
        if (data->map[counters->y][counters->x] == '1')
            return (NO_ERROR);
    }
    else
        if (data->map[counters->y][0] == '1' 
            && data->map[counters->y][data->w_res - 1] == '1')
            return (NO_ERROR);
    return (MAP_BORDER_ERROR); 
}

t_error check_elements(t_data *data, t_map_check *counters)
{
    if (data->map[counters->y][counters->x] == 'C')
        counters->c_count += 1;
    if (data->map[counters->y][counters->x] == 'E')
        counters->e_count += 1;
    if (data->map[counters->y][counters->x] == 'P')
        counters->p_count += 1;
    if (data->map[counters->y][counters->x] != 'C'
            && data->map[counters->y][counters->x] != 'E'
            && data->map[counters->y][counters->x] != 'P'
            && data->map[counters->y][counters->x] != '1'
            && data->map[counters->y][counters->x] != '0')
        return (UNKNOWN_MAP_ELEMENT);
    return (NO_ERROR);
}

t_error check_map(t_data *data)
{
    t_map_check counters;
    t_error     error;

    counters.x = 0;
    counters.y = 0;
    counters.c_count = 0;
    counters.e_count = 0;
    counters.p_count = 0;

    while (counters.y < data->h_res)
    {
        while (counters.x < data->w_res)
        {
            error = check_borders(data, &counters);
            if (error)
                return (error);
            error = check_elements(data, &counters);
            if (error)
                return (error);
            counters.x++;
        }
        counters.x = 0;
        counters.y++;
    }

    return (NO_ERROR);
}