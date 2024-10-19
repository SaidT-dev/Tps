ch = 'bonne continuation';
disp(['La taille de ch est: ', length(ch)])
disp(['La demension de ch est: ', size(ch)])
ch1 = 'Bonjour';
ch2 = 'Bonsoir';
upper(ch1)
upper(ch2)
lower(ch2)
a = abs(ch)
disp(['Le code ASCII de ch est: ', a])
setstr(a)
findstr(ch, 'n')
z = strcat('Etudiant n' ,num2str(127))