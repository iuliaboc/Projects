   M S B A M L   `   `   `  ����E  ADictionary, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null'clr-namespace:Dictionary
Dictionary  5   	   =#clr-namespace:Dictionary.ViewModelsDictionary.ViewModels  5   	   3clr-namespace:Dictionary.ViewsDictionary.Views  5   	       Dictionary.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   *localclr-namespace:Dictionary     5   	   :
viewmodels#clr-namespace:Dictionary.ViewModels     5   	   0viewsclr-namespace:Dictionary.Views     5   	     � Title$  
MainWindow��5
   	   $	��450��6   $	��800��6)    � 	Resources 5       �� DataType.   (Dictionary.ViewModels.AdministrativModel$   Dictionary.Views.Administrativ � DataContext(   "Dictionary.ViewModels.CautareModel   Dictionary.Views.Cautare.   (Dictionary.ViewModels.EntertainmentModel$   Dictionary.Views.Entertainment��%S  (��       5   6   *, +)(�� Z     5   0   *, +)(�� �     5   6   *, +)�� 5   
   administrativTemplate��"  66   .R�5         6"   �� 5      �� 5   
   cautareTemplate��"  60   .R�5         6   �� 5      �� 5   
   entertainmentTemplate��"  66   .R�5         6"   �� 5      5      .��5      � 
������� � ColumnDefinitions 5   
   �� 5      �� 5      �� 5      �� 5      �� 5       � RowDefinitions 5    
   �� 5!      �� 5"      �� 5#      �� 5$      �� 5%      .+�5(   
   ]� 
����ح�$��0��6+   $��0��68   $��5��6H   .+�5)      �� $	��300��6   .+�5*      �� $	��155��6   $	��150��6$   ��5+      �� 5,       �� 	UriSource$M GE:\Cursuri\Anul 2\Semestrul 2\MVP\Dictionary\Dictionary\Images\logo.png?�6'   5.      �� 5/      -   5        $��Administrativ��5/      
�������
����ح�$��Italic$�6_   $��15(�6r   6�   �� 50      -   5        $��Cautare��50      
�������
����ح�$��Italic$�6Y   $��15(�6l   6z   �� 51      -   5        $��Entertainment��51      
�������
����ح�$��Italic$�6_   $��15(�6r   6�   52      53      �� 55   
   $��0��6   $��1��6&   $��4��66   $��5��6J   ��6[   �� 56      57      