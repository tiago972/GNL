ES<-read.csv2("/Users/Tiago/Desktop/theme&decision.csv")
ES2<-na.omit(ES)
ES$note<- ifelse (ES$Niveau.de.certification.1=='A'|ES$Niveau.de.certification.1=='B',0,1)
ES$note<-as.factor(ES$note)
ES$note<-relevel(ES$note, ref="1")
ES$Type1<- ifelse (ES$Type=='Privé lucratif'|ES$Type=='Privé non lucratif', "Privé", "Publique")
ES$Type1<- as.factor(ES$Type1)
ES$Type1<-relevel(ES$Type1,ref="Publique")

a<-glm(ES$note~ES$Nombre.de.lits+ES$Type1+ES$PECM+ES$DPA, family='binomial')
summary(a)
exp(coefficients(a))
na.action(na.omit(c(1, NA)))

