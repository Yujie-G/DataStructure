figure
plot(T1_RBT(:,1),'Color','#0072BD');hold on;
plot(T2_RBT(:,1),'Color','#4DBEEE');hold on;
plot(T3_RBT(:,1),'Color','#0000FF');hold on;
legend("RBT type1 insert","RBT type2 insert","RBT type3 insert")
xlabel("数据规模 20000*")
ylabel("耗时 单位：微秒")
title("insert rate  RBT")

figure
plot(T1_RBT(:,2),'Color','#2E8B57');hold on;
plot(T2_RBT(:,2),'Color','#98FB98');hold on;
plot(T3_RBT(:,2),'Color','#006400');hold on;
legend("RBT type1 search","RBT type2 search","RBT type3 search")
xlabel("数据规模 20000*")
ylabel("耗时 单位：微秒")
title("search rate  RBT")

figure
plot(T1_RBT(:,3),'Color','#BC8F8F');hold on;
plot(T2_RBT(:,3),'Color','#FF6347');hold on;
plot(T3_RBT(:,3),'Color','#8B0000');hold on;
legend("RBT type1 delete","RBT type2 delete","RBT type3 delete")
xlabel("数据规模 20000*")
ylabel("耗时 单位：微秒")
title("delete rate  RBT")

