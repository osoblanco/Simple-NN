d1 <- read.table("student-mat.csv",sep=";",header=TRUE)
d2 <- read.table("student-por.csv",sep=";",header=TRUE)

d3=merge(d1,d2,by=c("school","sex","age","address","famsize","Pstatus","Medu","Fedu","Mjob","Fjob","reason","nursery","internet"))
print(nrow(d3)) # 382 students

#d3["school"]<-NULL
d3<-as.data.frame(sapply(d3,as.numeric))
d3Scaled<-as.data.frame(scale(d3[1:50]))#scale the input variables
d3Scaled[51:53]<-d3[51:53]

write.csv(d3Scaled, file = "SACdata.csv",row.names=FALSE)

d4<-read.csv("SACdata.csv")
