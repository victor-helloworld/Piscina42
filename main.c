#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	int	size;
	char	*ptr_str;
	char	*ptr_sep;
	char	*strs[3] = 	{	"a",
					"b", 
					"c"
				};
	size = 3;
	ptr_sep = "--";
	printf("=============================================\n");
	ptr_str = ft_strjoin(size, strs, ptr_sep);
	printf("\n=============================================\n");
	size = 1;
	size = 0;
	while (ptr_str[size])
		size++;
	printf("size: %d\n", size);
	return (0);
}
