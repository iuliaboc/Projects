   M S B A M L   `   `   `  ���� E  ADictionary, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null3clr-namespace:Dictionary.ViewsDictionary.Views  $    Dictionary.Views.Administrativ   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     @d2http://schemas.microsoft.com/expression/blend/2008     0localclr-namespace:Dictionary.Views     .��� 
�������  � ColumnDefinitions  �� $	��100 ��� �� ��  � RowDefinitions �� �� �� �� �� $��60 ��� �� �� �� �� �� .+��� $��0��$��0��$��ID��$��Times New Roman)�$��16(�$��Center=�$��Center=��� $��1��$��0�� �� 
IsReadOnly . ����  �� ElementName$
 date�� �� Path$ SelectedItem.Id� �� Mode$ TwoWay=��� $��3��$��0�� �� TextWrapping$
 Wrap=����� *	Curent.Id+�� $��0��$��1��$
��NUME��$��Times New Roman)�$��16(�$��Center=�$��Center=��� $��1��$��1�� . ���� $
 date��$ SelectedItem.Nume�$ TwoWay=��� $��3��$��1��$
 Wrap=����� *Curent.Nume+�� $��0��$��2��$��	CATEGORIE��$��Times New Roman)�$��16(�$��Center=�$��Center=��� $��1��$��2�� . ���� $
 date��$ SelectedItem.Categorie�$ TwoWay=��� $��3��$��2��$
 Wrap=����� *Curent.Categorie+�� $��0��$��3��$��	DESCRIERE��$��Times New Roman)�$��16(�$��Center=�$��Center=��� $��1��$��3�� . ���� $
 date��$ SelectedItem.Descriere�$ TwoWay=��� $��3��$��3��$
 Wrap=����� *Curent.Descriere+�� $��2��$��4��$	��155��$	��150������ $
 date��$ SelectedItem.Imagine��� $��3��$��4��$��60������ *Curent.Imagine+�� $��0��$��5��$��Adauga��
�������
����ح�$��Italic$�$��20(��� $��1��$��5��$��Modifica��
�������
����ح�$��Italic$�$��20(����� $ UpdateCommand��� $��2��$��5��$��Sterge��
�������
����ح�$��Italic$�$��20(��� $��3��$��5��$��Imagine��
�������
����ح�$��Italic$�$��20(��� -   $
��date��$��6��$��6��$��4������ *Date+ �� UpdateSourceTrigger$ PropertyChanged=�$ TwoWay=� �� View �� .P��� $��Id��	 �� Width$		 120��
 �� DisplayMemberBinding
 �� $ Id��� $
��Nume��$	 50��
 �� $
 Nume��� $��	Descriere��$		 150��
 �� $ 	Descriere��� $��	Categorie��$		 150��
 �� $ 	Categorie��� $��Imagine��$		 150��
 �� $ Imagine�