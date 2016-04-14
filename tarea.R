setwd("C:/Users/USER/Documents")
mydata <- read.table("NuAstro_4yr_IceCube_Data.txt",header=TRUE)##leer data
is.nan("mydata")##identificar los nan
mydata<-na.omit(mydata)##una forma de quitar los nan
mydata<-mydata[complete.cases(mydata),]##otra forma de quitar los nan
mean_ang<-aggregate(submydatanan$Med_Ang_Res_deg, list(topology =submydatanan$Topology), mean)##promedio mean_ang
##-------------------
##algoritm for MJ: mjd2posix
mjd2posix<- function(MJD)
  ##MJD<-mydata$Time_MJD
{format(as.POSIXct('1899-12-30')+(MJD*24*60*60),"%Y-%m-%d %H:%M:%OS3")}
  #return(Time_GMT)
#--------------------------
#Aplicando la función
MJD1<-mydata$Time_MJD
Time_GMT<-mjd2posix(MJD1)
##---------------------------------
##Para agregar
mydata_GMT<-data.frame(mydata,Time_GMT)
  #return(mydata_GMT)
##-----------------------------------
evt_month <- function(Data,mes)
{  fecha_x= Data[,10]
   columnas= nrow(Data)
  c=0
  for (i in 1:columnas)
  {m = substring(fecha_x[i],6,7)
    month = as.integer(m)
    if (month == mes)
    {c = c + 1}
  }
  return(c)
}
#---------------------
y<-evt_month(mydata_GMT,3)
#--------------------------------
plot(mydata$Declination_deg,mydata$RA_deg)#grafico coordenadas ecuatoriales
#---------------------------------
