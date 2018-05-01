/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:22:39 by amineau           #+#    #+#             */
/*   Updated: 2018/05/01 12:56:36 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void    nm(char *ptr)
{
    (void)ptr;
}

int     main (int ac, char **av)
{
    int         fd;
    char        *ptr;
    struct stat buf;

    if (ac != 2)
        return (0);
    if ((fd = open(av[1], O_RDONLY)) < 0)
        return (0);
    if (fstat(fd, &buf) < 0)
        return (0);
    if ((ptr = nmap(0, buf.st_size, PROT_READ,MAP_PRIVATE, fd, 0)) == MAP_FAILED)
        return (0);
    nm(ptr);
    if (munmap(ptr, buf.st_size) < 0)
        return (0);
    return (0);
}