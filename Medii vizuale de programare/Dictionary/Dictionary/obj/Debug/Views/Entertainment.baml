   M S B A M L   `   `   `  ����E  ADictionary, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null3clr-namespace:Dictionary.ViewsDictionary.Views  5      $    Dictionary.Views.Entertainment   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      0localclr-namespace:Dictionary.Views     5      .��5	      � 
�������  � ColumnDefinitions  5
   
   �� 5      6!   �� 5      6!    � RowDefinitions 5   
   �� 5      6   �� 5      6   �� 5      6   .+�5   
   �� $��1��6   ��6   ��  �� Path$ Curent.Descriere� �� UpdateSourceTrigger$ PropertyChanged=� �� Mode$ TwoWay=�6{   �� 5   
   $��2��6   ��6   �� $ Raspuns�6?   �� 5   
   ��6   �� $ Curent.Imagine�69   �� 5   
   $��1��6   $��2��6    ��61   �� $ Verifica�6T   � 5   
   $��1��6   $��2��6    5      �� 5      6"   �� 5      6"   �� 5      6"   .+�5      �� -   5        $��START��5      ��6%   �� $ StartCommand�6a   �� 5      -   5        $��1��5      $
��NEXT��6"   ��61   �� $ NextCommand�6k   �� 5      $��2��6   $��FINISH��6#   ��64   �� $ FinishCommand�y�6[   �� $ 
sfarsitJoc�$ PropertyChanged=�6�   5       5!      5"      