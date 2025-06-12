/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:56:47 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 18:04:36 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recipe_generator.h"

struct Recipe *create_custom_recipe(void)
{
	Ingredients *ingredients = NULL;
	TasteProfile *taste = NULL;
	Recipe *recipe = NULL;

	ingredients = get_current_ingredients();
	if (!ingredients)
		return NULL;
	taste = get_user_taste_profile();
	if (!taste)
	{
		free_ingredients(ingredients);
		return NULL;
	}
	do
	{
		free_recipe(recipe);
		recipe = create_recipe(ingredients, taste);
		if (!recipe)
		{
			free_ingredients(ingredients);
			free_taste_profile(taste);
			return NULL;
		}
	} while (!get_user_approval(recipe));
	free_ingredients(ingredients);
	free_taste_profile(taste);
	return recipe;
}