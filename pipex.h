/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:09:08 by yunseo            #+#    #+#             */
/*   Updated: 2024/05/26 02:01:32 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <wait.h>
# include <errno.h>

#endif

/*
fcntl.h
int open(const char *__file, int __oflag, ...)

unistd
int close(int __fd)
ssize_t read(int __fd, void *__buf, size_t __nbytes)
ssize_t write(int __fd, const void *__buf, size_t __n)

stdlib
void *malloc(size_t __size)
void free(void *__ptr)

stdio.h
void perror(const char *__s)

string.h
char *strerror (int __errnum)

unistd.h
int access(const char *__name, int __type)
int dup(int __fd)
int dup2(int __fd, int __fd2)
int execve(const char *__path, char *const *__argv, char *const *__envp)

stdlib.h
void exit(int __status)

unistd.h
pid_t fork(void)
int pipe(int *__pipedes)
int unlink(const char *__name)

wait.h
pid_t wait(int *__stat_loc)
pid_t waitpid(pid_t __pid, int *__stat_loc, int __options)
*/
