setwd("C:/Users/USER/Documents")
mydata <- read.table("NuAstro_4yr_IceCube_Data.txt",header=TRUE)##leer data
is.nan("mydata")
mydatanan<-mydata[complete.cases(mydata),]##quito nan
submydatanan<-mydatanan[,8:9]##separo para promediar
##-----------------------------------------
aggregate(x=submydatanan,by = list(submydatanan$Med_Ang_Res_deg, submydatanan$Topology),FUN="mean")## no estoy seguro
aggregate(submydatanan$Med_Ang_Res_deg, list(topology =submydatanan$Topology), mean)##correcto promedio
format(as.POSIXct('1899-12-30')+(mydata$Time_MJD*24*60*60),"%Y-%m-%d %H:%M:%OS3"##convierte MDJ to GMT
##mjd2posix
time<-format(as.POSIXct('1899-12-30')+(mydata$Time_MJD*24*60*60),"%Y-%m-%d %H:%M:%OS3")
NuevosDatos = data.frame(mydata, time)
plot(NuevosDatos$Declination_deg,NuevosDatos$RA_deg)##grafico coordenadas ecuatoriales