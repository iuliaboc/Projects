   M S B A M L   `   `   `  ����E  ADictionary, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null3clr-namespace:Dictionary.ViewsDictionary.Views  5      $    Dictionary.Views.Administrativ   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      0localclr-namespace:Dictionary.Views     5      .��5	      � 
�������  � ColumnDefinitions  5
   
   �� 5      $	��100 �6   �� 5      �� 5      �� 5       � RowDefinitions 5   
   �� 5      �� 5      �� 5      �� 5      �� 5      $��60 �6   �� 5      �� 5      �� 5      �� 5      �� 5      �� 5      .+�5   
   �� $��0��6   $��0��6    $��ID��6-   $��Times New Roman)�6:   $��16(�6W   $��Center=�6e   $��Center=�6�   6�   �� 5   
   $��1��6   $��0��6"    �� 
IsReadOnly . ��6/   ��  �� ElementName$
 date�� �� Path$ SelectedItem.Id� �� Mode$ TwoWay=�6�   �� 5   
   $��3��6   $��0��6"    �� TextWrapping$
 Wrap=�6/   ��6C   �� *	Curent.Id+$ TwoWay=�6m   �� 5    
   $��0��6   $��1��6    $
��NUME��6-   $��Times New Roman)�6<   $��16(�6Y   $��Center=�6g   $��Center=�6�   6�   �� 5!   
   $��1��6   $��1��6"    . ��6/   �� $
 date��$ SelectedItem.Nume�$ TwoWay=�6�   �� 5"   
   $��3��6   $��1��6"   $
 Wrap=�6/   ��6C   �� *Curent.Nume+$ TwoWay=�6o   �� 5#   
   $��0��6   $��2��6    $��	CATEGORIE��6-   $��Times New Roman)�6A   $��16(�6^   $��Center=�6l   $��Center=�6�   6�   �� 5$   
   $��1��6   $��2��6"    . ��6/   �� $
 date��$ SelectedItem.Categorie�$ TwoWay=�6�   �� 5%   
   $��3��6   $��2��6"   $
 Wrap=�6/   ��6C   �� *Curent.Categorie+$ TwoWay=�6t   �� 5&   
   $��0��6   $��3��6    $��	DESCRIERE��6-   $��Times New Roman)�6A   $��16(�6^   $��Center=�6l   $��Center=�6�   6�   �� 5'   
   $��1��6   $��3��6"    . ��6/   �� $
 date��$ SelectedItem.Descriere�$ TwoWay=�6�   �� 5(   
   $��3��6   $��3��6"   $
 Wrap=�6/   ��6C   �� *Curent.Descriere+$ TwoWay=�6t   �� 5)   
   $��2��6O   $��4��6_   $	��155��6p   $	��150��6|   ��6   �� $
 date��$ SelectedItem.Imagine�6�   �� 5*   
   $��3��62   $��4��6B   $��60��6O   ��6   �� *Curent.Imagine+6\   �� 5+   
   $��0��6   $��5��6!   $��Adauga��6.   
�������
����ح�$��Italic$�6m   $��20(�6�   ��6�   �� $ 
AddCommand�6�   �� 5,   
   $��1��6   $��5��6!   $��Modifica��6.   
�������
����ح�$��Italic$�6o   $��20(�6�   ��6�   �� $ UpdateCommand�6�   �� 5-   
   $��2��6   $��5��6!   $��Sterge��6.   
�������
����ح�$��Italic$�6m   $��20(�6�   ��6�   �� $ DeleteCommand�6�   �� 5.   
   $��3��6   $��5��6!   $��Imagine��6.   
�������
����ح�$��Italic$�6n   $��20(�6�   ��6�   �� $ LoadImageCommand�6�   �� 5/   
   -   5        $
��date��5/   E   $��6��6   $��6��6    $��4��61   ��6Q   �� *Date+ �� UpdateSourceTrigger$ PropertyChanged=�$ TwoWay=� �� View 50      �� 51      .P�52      �� $��Id��6%   	 �� Width$		 120��61   
 �� DisplayMemberBinding
 6=   �� $ Id�$ TwoWay=��� 53      $
��Nume��6%   $	 50��63   
 6>   �� *Nume+$ TwoWay=��� 54      $��	Descriere��6%   $		 150��68   
 6D   �� $ 	Descriere��� 55      $��	Categorie��6%   $		 150��68   
 6D   �� $ 	Categorie��� 56      $��Imagine��6%   $		 150��66   
 6B   �� $ Imagine�57      59      5:      5;      