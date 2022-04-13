/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:45:36 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 18:45:37 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

void	swap(int arr[], int low, int high);
int		get_pivot(int arr[], int left, int right);
int		partition(int arr[], int left, int right);
void	quicksort(int arr[], int left, int right);

#endif
