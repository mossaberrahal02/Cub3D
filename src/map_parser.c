#include "../inc/cub3d.h"

// Function to determine player direction based on the map character
void set_player_orientation(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

char **parse_map(const char *filename, int *width, int *height, t_player *player)
{
	FILE *file = fopen(filename, "r");
	if (!file)
	{
		printf("Error: Could not open map file.\n");
		return NULL;
	}

	char **map = malloc(100 * sizeof(char *));
	char line[1024];
	int row = 0;
	int player_found = 0;

	while (fgets(line, sizeof(line), file))
	{
		map[row] = strdup(line);
		// Search for player start position
		for (int col = 0; col < (int)strlen(map[row]); col++)
		{
			if (strchr("NSEW", map[row][col]))
			{
				player->x = col + 0.5; // Center the player in the block
				player->y = row + 0.5;
				set_player_orientation(player, map[row][col]);
				player_found = 1;
				map[row][col] = '0'; // Replace player char with empty space
			}
		}
		row++;
	}
	fclose(file);

	*width = row > 0 ? strlen(map[0]) : 0;
	*height = row;

	if (!player_found)
	{
		printf("Error: No player start position found!\n");
		return NULL;
	}

	return map;
}
