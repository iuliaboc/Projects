   M S B A M L   `   `   `  ����E  ADictionary, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null3clr-namespace:Dictionary.ViewsDictionary.Views  5          Dictionary.Views.Cautare   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      0localclr-namespace:Dictionary.Views     5      .��5
      � $��0,0,0,20q�6   ��5   
   �� 5        �� ImageSource$S  ME:\Cursuri\Anul 2\Semestrul 2\MVP\Dictionary\Dictionary\Images\background.png��6    j� Stretch$ UniformToFill=�6u    � RowDefinitions 5   
   �� 5      $
��Auto �6   �� 5      $��* �6   �� 5      $
��Auto �6   .+�5   
   �� -   5         ��Name$
 cBox��5      $��120,0,278,0.4q�6l   ��6!   ��  �� Path$ 	Categorii� �� SelectedValue 6H   �� *	Categorie+5      �� 5   
   $��SEARCH:��6   $��Right=�6#   $��Times New Roman)�6?   $��16(�6\   $��Bottom=�5      $	��224��6/   $��21��6;   $��0,0,389,336.6q�6G   $��1��6^   �� 5   
   -   5         ��Name$ txtAuto��5   @   $��Right=�5      $��Bottom=�6.   $��25��5      $	��502��6   $��0,0,10,336.6q�6*    �� TextWrapping$ NoWrap=�6Q   $��1��6g   ��6t   �� *	Cautare+ �� UpdateSourceTrigger$ PropertyChanged=��� 5   
   -   5        	 ��Name$	 lbSuggestion��5      
�������$��1��5   &   $y�Visible=�63   $��Right=�5      $	��Top=�6.   $	��502��6F   $��0,37.6,10,0q�6R   ��5   (   �� $ CuvintePeCautari�
 �� SelectedItem
 6V   �� *
CuvantAles+ �� Mode$ TwoWay=���5      �� 5      .R�5      ��  �� Orientation$ 
Horizontal=�6!   .+�5       �� ��6$   �� $
 Nume�6A   5!      5"      5$      �� 5%   
   $��449,125.6,10,39.6q�6;   $��1��6V   ��6   �� $ CuvantAles.Imagine�6V   �� 5&   
   $��1��6   $
��Left=�6   $��120,179.6,0,0q�68   $	��Top=�6O   $	��234��6g   $��14(�6�   $��Italic$�6�   
���   �$��
ExtraBlack"�6�   ��6s   �� $ CuvantAles.Id�$ TwoWay=���6�   Z� 6�   �� 5'   
   $��1��6   $��31��6   $
��Left=�6)   $��120,208.6,0,0q�6D   $	��Top=�6[   $	��234��6s   
���   �$��14(�6�   $��Italic$�6�   $��
ExtraBlack"�6�   ��6   �� $ CuvantAles.Nume�$ TwoWay=�6�   �� 5(   
   $��1��6   $��78��6   $
��Left=�6)   $��120,239.6,0,0q�6D   $	��Top=�6[   $	��291��6s   
���   �$��14(�6�   $��Italic$�6�   $��
ExtraBlack"�6�   ��6   �� $ CuvantAles.Descriere�$ TwoWay=�6�   �� 5)   
   $��ID��6   $
��Left=�6   $��Times New Roman)�68   $��16(�6U   $��1��6c   $��30,180,0,112.6q�6p   $��27��6�   �� 5*   
   $��	DESCRIERE��6   $
��Left=�6$   $��Times New Roman)�6?   $��16(�6\   $��1��6j   $��37��6w   $��30,239.6,0,0q�6�   $	��Top=�6�   $��99��6�   �� 5+   
   $
��NUME��6   $
��Left=�6   $��Times New Roman)�6:   $��16(�6W   $��1��6e   $��38��6r   $��
30,210,0,0q�6~   $	��Top=�6�   $��55��6�   �� 5,   
   -   5         ��Name$ 	Categorie��5,   Z   $��1��6   $��35��6   $
��Left=�6)   $��120,0,0,39.6q�6D   $��Bottom=�6m   $	��234��6�   
���   �$��14(�6�   $��Italic$�6�   $��
ExtraBlack"�6  ��6�   �� $ CuvantAles.Categorie�$ TwoWay=�6  �� 5-   
   -   5        $ label2_Copy1��5-   �   $��	CATEGORIE��6   $��Times New Roman)�6$   $��16(�6A   $��1��6O   $��28��6\   $
��Left=�6h   $��
30,300,0,0q�6�   $	��Top=�6�   �� 5.   
   $��	CATEGORIE��6   $��Times New Roman)�6$   $��16(�6A   $
��Left=�6O   $��0,-3,0,0q�6j   $	��Top=�6|   $	��120��6�    J� RenderTransformOrigin$ 0.5,0.5&�6�   $��2��6�   6�   50      51      