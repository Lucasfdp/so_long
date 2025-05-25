t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof(*result));
	if (!result)
	{
		return (NULL);
	}
	result->value = content;
	result->next = NULL;
	return (result);
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize_ps(t_stack *lst)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = lst;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}