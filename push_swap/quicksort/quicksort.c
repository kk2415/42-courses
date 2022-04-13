/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunkim <kyunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:45:30 by kyunkim           #+#    #+#             */
/*   Updated: 2021/08/21 18:45:31 by kyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

void	swap(int arr[], int low, int high)
{
	int	temp;

	temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;
}

int	get_pivot(int arr[], int left, int right)
{
	int	temp[3];

	temp[0] = left;
	temp[1] = (left + right) / 2;
	temp[2] = right;
	if (arr[temp[0]] > arr[temp[1]])
		swap(temp, 0, 1);
	if (arr[temp[1]] > arr[temp[2]])
		swap(temp, 1, 2);
	if (arr[temp[0]] > arr[temp[1]])
		swap(temp, 0, 1);
	return (temp[1]);
}

int	partition(int arr[], int left, int right)
{
	int	pivot;
	int	low;
	int	high;

	pivot = arr[get_pivot(arr, left, right)];
	low = left + 1;
	high = right;
	swap(arr, get_pivot(arr, left, right), left);
	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot <= arr[high] && high >= (left + 1))
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	swap(arr, left, high);
	return (high);
}

void	quicksort(int arr[], int left, int right)
{
	int	pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}
