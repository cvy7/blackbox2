#ifndef PPCH8_32TD_HH
#define PPCH8_32TD_HH

void MainWindow::load_arhive8_32td(QFile *arhive){
#include "ppch8_32td.h"
QByteArray arhive_bytes=arhive->readAll();
tarhiv8_32u arhiveu8_32;
int size=arhive_bytes.size();
for(int i=0; i<sizeof (tarhiv8_32);i++){
    if(i<size)
        arhiveu8_32.arhive_bytes[i]=arhive_bytes[i];
    else arhiveu8_32.arhive_bytes[i]=0;
}
//***********************************************************************************************************
QString cell="test";
int m_addr_hmi=0;
int m_addr_conv=0;
int addr_du=0;

//QString cell= QString::number(sizeof (tarhiv),16);
//QString cell= QString::fromLocal8Bit((const char*)&arhiveu8_32.arhive_data.str_stop[0], 16);
//QString cell= QString::fromLocal8Bit((const char*)arhiveu8_32.arhive_data.str_ram, 16);
int row=1,column=0;
ui->table_pars_pusk->item(row,column)->setText("Биты conv");
ui->table_pars_stop->item(row,column)->setText("Биты conv");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.convb.convs,2);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.convb.convs,2);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
row=0;column=0;

ui->table_diags->item(row,column)->setText("conv stop");
ui->table_diags->item(2,column++)->setText("conv pusk");
ui->table_diags->item(row,column)->setText("heat_on");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.heat_on,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.heat_on,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("c_heat_on");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.command_heat_on,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.command_heat_on,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("ready");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.ready,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.ready,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("c_ready");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.command_ready,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.command_ready,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.err,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.err,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("bloked");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.bloked,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.bloked,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("conn_err");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.conn_err,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.conn_err,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("c_reset");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.command_reset,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.command_reset,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("switch_on");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.switch_on,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.switch_on,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_so");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.err_so,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.err_so,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_bk");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.err_bk,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.err_bk,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("mest_upr");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.mestnoe_upr,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.mestnoe_upr,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("so_on");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.so_on,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.so_on,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("pusk_so");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.pusk_so,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.pusk_so,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("heartbeat");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.heartbeat,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.heartbeat,2);
ui->table_diags->item(2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("r15");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.convb.convb.r15,2);
ui->table_diags->item(1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convb.r15,2);
ui->table_diags->item(2,column)->setText(cell);

//**********************************************************************************************************
row=1;column=4;m_addr_hmi=200;m_addr_conv=300;addr_du=0;
long tmp;
for(row=1;row<49;row++){
    cell = QString::number(m_addr_hmi++);
    ui->table_sets->item(row,column)->setText(cell);
    cell = QString::number(addr_du++);
    ui->table_sets->item(row,column+2)->setText(cell);
}
row=1;column=0;
ui->table_sets->item(row,column++)->setText("(0)us Напр.задан.");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.us);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.us);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.us - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);

row++;column=0;
ui->table_sets->item(row,column++)->setText("ps Мощ.задан.");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.ps);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ps);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ps - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("dvr");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.dvr);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.dvr);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.dvr - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("is");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.is);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.is);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.is - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("uo_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.uo_max);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.uo_max);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.uo_max - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("ki_uo");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.ki_uo);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ki_uo);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ki_uo - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("io_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.io_max);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.io_max);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.io_max - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("io_maxc");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.io_maxc);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.io_maxc);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.io_maxc - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("ki_io");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.ki_io);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ki_io);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ki_io - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("ud_min");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.ud_min);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ud_min);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ud_min - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("ud_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.ud_max);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ud_max);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ud_max - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("ki_ud");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.ki_ud);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ki_ud);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ki_ud - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("id_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.id_max);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.id_max);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.id_max - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("ki_id");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.ki_id);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ki_id);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.ki_id - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("fo_min");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.fo_min);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.fo_min);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.fo_min - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("fo_norm");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.fo_norm);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.fo_norm);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.fo_norm - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("fo_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.fo_max);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.fo_max);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.fo_max - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("co опережение");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.co);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.co);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.co - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("cs пусковое опереж.");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.cs);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.cs);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.cs - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("(19)Биты diags");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagss,2);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagss,2);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagss - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("t_maxp");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.t_maxp);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.t_maxp);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)((unsigned short *)&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.t_maxp - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("doors");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.doors);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.doors);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.doors - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("wtr");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.wtr);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.wtr);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.wtr - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("uop ед.пусковое напряж.");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.uop);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.uop);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.uop - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("psp ед.пусковая мощн.");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.psp);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.psp);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.psp - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("ussstep ед.шаг напр.");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.usstep);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.usstep);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.usstep - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("psstep ед.шаг мощн.");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.psstep);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.psstep);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.psstep - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("nmp пуск.Кинверт");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.nmp);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.nmp);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.nmp - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("kpup к рег.U пуск");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.kpup);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.kpup);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.kpup - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("kppp к рег.P пуск");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.kppp);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.kppp);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.kppp - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("kiup к рег.U пуск");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.kiup);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.kiup);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.kiup - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("kipp к рег.P пуск");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.kipp);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.kipp);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.kipp - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("nmx макс.Кинверт");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.nmx);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.nmx);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.nmx - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("proto0");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.proto0);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.proto0);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.proto0 - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("(34)proto1");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.proto1);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.proto1);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.proto1 - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("k_rec");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.k_rec);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.k_rec);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.k_rec - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("vp скор.подема.P кВт");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.vp);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.vp);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.vp - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("vpp");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.vpp);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.vpp);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.vpp - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("tvp");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.tvp);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.tvp);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.tvp - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("par0");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.par0);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.par0);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.par0 - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("par1");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.par1);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.par1);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.par1 - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
row++;column=0;
ui->table_sets->item(row,column++)->setText("sinc");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.sinc);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.sinc);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.sinc - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
/*
for(int u=0;u<5;u++){
row++;column=0;
QString text=QString::number(u);
ui->table_sets->item(row,column++)->setText("mod_mask["+text+"]");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.mod_mask[u]);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.mod_mask[u]);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.mod_mask[u] - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);
}
*/
row++;column=0;
ui->table_sets->item(row,column++)->setText("f_sel Выбор фильтра 0-rc 1-fir");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.f_sel);
ui->table_sets->item(row,column++)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.f_sel);
ui->table_sets->item(row,column++)->setText(cell);
tmp=(long)(&arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.f_sel - &arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.convb.convs);
cell = QString::number(tmp+m_addr_conv);
ui->table_sets->item(row,column+2)->setText(cell);


//*********************************************************************************************************
row=3;column=0;

ui->table_diags->item(row,column)->setText("diags stop");
ui->table_diags->item(row+2,column++)->setText("diags pusk");
ui->table_diags->item(row,column)->setText("res_err");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.res_err,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.res_err,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("inv_on");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.inv_on,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.inv_on,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("diag_mod");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.diag_mod,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.diag_mod,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("regulator");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.regulator,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.regulator,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("pll");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.pll,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.pll,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("ud");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.ud,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.ud,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("em_stop");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.em_stop,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.em_stop,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("uo");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.uo,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.uo,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("io");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.io,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.io,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("conn");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.conn,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.conn,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("fo");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.fo,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.fo,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("r11");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.r11,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.r11,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("id");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.id,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.id,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("rvpr");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.rvpr,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.rvpr,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("kzp");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.kzp,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.kzp,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("global_on");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.diags.diagsb.global_on,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.diags.diagsb.global_on,2);
ui->table_diags->item(row+2,column++)->setText(cell);
//*********************************************************************************************************
row=2;column=0;
ui->table_pars_pusk->item(row,column)->setText("Биты plst");
ui->table_pars_stop->item(row,column)->setText("Биты plst");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.plst.plsts,2);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.plst.plsts,2);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row=6;column=0;

ui->table_diags->item(row,column)->setText("plst stop");
ui->table_diags->item(row+2,column++)->setText("plst pusk");
ui->table_diags->item(row,column)->setText("err");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("e_e_stop");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err_emer_stop,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err_emer_stop,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_uo_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err_uo_max,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err_uo_max,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_io_maxc");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err_io_maxc,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err_io_maxc,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_io_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err_io_max,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err_io_max,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_fo_min");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err_fo_min,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err_fo_min,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_fo_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err_fo_max,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err_emer_stop,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_mod");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err_mod,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err_mod,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("err_id_max");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.err_id_max,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.err_id_max,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("reg_uo");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.reg_uo,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.reg_uo,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("reg_io");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.reg_io,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.reg_io,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("pll_fo_not_lock");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.pll_fo_not_lock,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.pll_fo_not_lock,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("r12");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.r12,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.r12,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("reg_not_in_limit");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.reg_not_in_limit,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.reg_not_in_limit,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("r14");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.r14,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.r14,2);
ui->table_diags->item(row+2,column++)->setText(cell);

ui->table_diags->item(row,column)->setText("e_off");
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.plst.plstb.e_off,2);
ui->table_diags->item(row+1,column)->setText(cell);
cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.plst.plstb.e_off,2);
ui->table_diags->item(row+2,column++)->setText(cell);
//********************************************************************************************
row=3;column=0;
ui->table_pars_pusk->item(row,column)->setText("P Мощность");
ui->table_pars_stop->item(row,column)->setText("P Мощность");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.P/10.);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.P/10.);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("ps зад.мощ");
ui->table_pars_stop->item(row,column)->setText("ps зад.мощ");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.ps/10.);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.ps/10.);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("ps2 ед.зад.мощ");
ui->table_pars_stop->item(row,column)->setText("ps2 ед.зад.мощ");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.ps2);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.ps2);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("psv огр.зад.мощ");
ui->table_pars_stop->item(row,column)->setText("psv огр.зад.мощ");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.psv/10.);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.psv/10.);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("fou Част.");
ui->table_pars_stop->item(row,column)->setText("fou Част.");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.fou);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.fou);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("id Ток");
ui->table_pars_stop->item(row,column)->setText("id Ток");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.id);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.id);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("iou Ток вых");
ui->table_pars_stop->item(row,column)->setText("iou Ток вых");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.iou);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.iou);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("is Ток вых.задан");
ui->table_pars_stop->item(row,column)->setText("is Ток вых.задан");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.is);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.is);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("uou Напр.вых");
ui->table_pars_stop->item(row,column)->setText("uou Напр.вых");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.uou);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.uou);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("us Напр.вых.задан");
ui->table_pars_stop->item(row,column)->setText("us Напр.вых.задан");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.us);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.us);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("us2 ед.Напр.вых.задан");
ui->table_pars_stop->item(row,column)->setText("us2 ед.Напр.вых.задан");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.us2);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.us2);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("ud Напр.выпр");
ui->table_pars_stop->item(row,column)->setText("ud Напр.выпр");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.ud);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.ud);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("err_cod");
ui->table_pars_stop->item(row,column)->setText("err_cod");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.err_cod[0]);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.err_cod[0]);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("t_max измереная");
ui->table_pars_stop->item(row,column)->setText("t_max измереная");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.t_max);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.t_max);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("t_maxp заданная");
ui->table_pars_stop->item(row,column)->setText("t_maxp заданная");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.t_maxp);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.t_maxp);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("t_water");
ui->table_pars_stop->item(row,column)->setText("t_water");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.t_water);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.t_water);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("rashod");
ui->table_pars_stop->item(row,column)->setText("rashod");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.rashod);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.rashod);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("io_2k(ed) Ток 2 коммутации в ед.");
ui->table_pars_stop->item(row,column)->setText("io_2k(ed) Ток 2 коммутации в ед.");
for(column=1;column<32;column++){
    cell = QString::number((short)arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.io_2k);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number((short)arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.io_2k);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("uo_2k(ed) Напр.2 коммутации в ед.");
ui->table_pars_stop->item(row,column)->setText("uo_2k(ed) Напр.2 коммутации в ед.");
for(column=1;column<32;column++){
    cell = QString::number((short)arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.uo_2k);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number((short)arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.uo_2k);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("ioc Ток коммутации в ед");
ui->table_pars_stop->item(row,column)->setText("ioc Ток коммутации в ед");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.ioc);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.ioc);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("nmd Инверт.1-255");
ui->table_pars_stop->item(row,column)->setText("nmd Инверт.1-255");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.nmd);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.nmd);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("kn Инверт");
ui->table_pars_stop->item(row,column)->setText("kn Инверт");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.kn);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.kn);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("kpu коэфф.рег.U");
ui->table_pars_stop->item(row,column)->setText("kpu коэфф.рег.U");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.kpu);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.kpu);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("kiu коэфф.рег.U");
ui->table_pars_stop->item(row,column)->setText("kiu коэфф.рег.U");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.kiu);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.kiu);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("kpp коэфф.рег.U");
ui->table_pars_stop->item(row,column)->setText("kpp коэфф.рег.U");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.kpp);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.kpp);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("kip коэфф.рег.U");
ui->table_pars_stop->item(row,column)->setText("kip коэфф.рег.U");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.kip);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.kip);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("uo_max0(ed) Напр.0 п/пер в ед");
ui->table_pars_stop->item(row,column)->setText("uo_max0(ed) Напр.0 п/пер в ед");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.uo_max0);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.uo_max0);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("uo_max2 Напр.2 п/пер в ед");
ui->table_pars_stop->item(row,column)->setText("uo_max2 Напр.2 п/пер в ед");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.uo_max2);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.uo_max2);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("io_max0(ed) Ток 0 п/пер в ед");
ui->table_pars_stop->item(row,column)->setText("io_max0(ed) Ток 0 п/пер в ед");
for(column=1;column<32;column++){
    cell = QString::number((short)arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.io_max0);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number((short)arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.io_max0);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("fou_aic Част.тест");
ui->table_pars_stop->item(row,column)->setText("fou_aic Част.тест");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.fou_aic);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.fou_aic);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
for(int u=0; u<10; u++){
    row++;column=0;
    QString text=QString::number(u);
    ui->table_pars_pusk->item(row,column)->setText("t["+text+"]");
    ui->table_pars_stop->item(row,column)->setText("t["+text+"]");
    for(column=1;column<32;column++){
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.t[u]);
        ui->table_pars_stop->item(row,column)->setText(cell);
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.t[u]);
        ui->table_pars_pusk->item(row,column)->setText(cell);
    }
}
/*
for(int u=0; u<72; u++){
    row++;column=0;
    QString text=QString::number(u);
    ui->table_pars_pusk->item(row,column)->setText("modstat["+text+"]");
    ui->table_pars_stop->item(row,column)->setText("modstat["+text+"]");
    for(column=1;column<32;column++){
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.modstat[u],2);
        ui->table_pars_stop->item(row,column)->setText(cell);
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.modstat[u],2);
        ui->table_pars_pusk->item(row,column)->setText(cell);
    }
}

for(int u=0; u<5; u++){
    row++;column=0;
    QString text=QString::number(u);
    ui->table_pars_pusk->item(row,column)->setText("err_parity["+text+"]");
    ui->table_pars_stop->item(row,column)->setText("err_parity["+text+"]");
    for(column=1;column<32;column++){
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.err_parity[u],2);
        ui->table_pars_stop->item(row,column)->setText(cell);
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.err_parity[u],2);
        ui->table_pars_pusk->item(row,column)->setText(cell);
    }
}

for(int u=0; u<5; u++){
    row++;column=0;
    QString text=QString::number(u);
    ui->table_pars_pusk->item(row,column)->setText("err_power["+text+"]");
    ui->table_pars_stop->item(row,column)->setText("err_power["+text+"]");
    for(column=1;column<32;column++){
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.err_power[u],2);
        ui->table_pars_stop->item(row,column)->setText(cell);
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.err_power[u],2);
        ui->table_pars_pusk->item(row,column)->setText(cell);
    }
}

for(int u=0; u<5; u++){
    row++;column=0;
    QString text=QString::number(u);
    ui->table_pars_pusk->item(row,column)->setText("mod_mask["+text+"]");
    ui->table_pars_stop->item(row,column)->setText("mod_mask["+text+"]");
    for(column=1;column<32;column++){
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.mod_mask[u],2);
        ui->table_pars_stop->item(row,column)->setText(cell);
        cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.mod_mask[u],2);
        ui->table_pars_pusk->item(row,column)->setText(cell);
    }
}
*/
row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("f_sel Выбор фильтра 0-rc 1-fir");
ui->table_pars_stop->item(row,column)->setText("f_sel Выбор фильтра 0-rc 1-fir");
for(column=1;column<32;column++){
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.f_sel);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number(arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.f_sel);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}

row++;column=0;
ui->table_pars_pusk->item(row,column)->setText("Io_max1(ed) Должен быть > 0 при правильно подключенном трансформаторе ОС");
ui->table_pars_stop->item(row,column)->setText("Io_max1(ed) Должен быть > 0 при правильно подключенном трансформаторе ОС");
for(column=1;column<32;column++){
    cell = QString::number((short)arhiveu8_32.arhive_data.tconv_data_stop[column-1].tconv_data.io_max1);
    ui->table_pars_stop->item(row,column)->setText(cell);
    cell = QString::number((short)arhiveu8_32.arhive_data.tconv_data_start[column-1].tconv_data.io_max1);
    ui->table_pars_pusk->item(row,column)->setText(cell);
}
/*
row=9;
for(column=1; column<17; column++){
QString text=QString::number(column-1);
ui->table_diags->item(row,column)->setText("mod["+text+"]");
}
for(int u=0; u<5; u++){
    row++;column=0;
    QString text=QString::number(u);
    ui->table_diags->item(row,column)->setText("mod_mask["+text+"]");
    int mask=arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.mod_mask[u];
    for(column=1; column<17; column++){
        cell = QString::number( mask & 1,2);
        ui->table_diags->item(row,column)->setText(cell);
        mask>>=1;
    }
}

//***************************************************************************************
row=0;column=0;
//err & err_dattoka & err_termodat & err_udover & err_us_low & err_in_t_max & err_sinc &
//--e2_o_vs_main & o_vs_podp & err_d_link & e2_uvt13 & e2_uvt24 & e_udover & err_summ & e2_inv_on & not m2r,
ui->table_drv->item(row,column++)->setText("modstat_stop");
ui->table_drv->item(row,column++)->setText("(0)not m2r");
ui->table_drv->item(row,column++)->setText("(1)e2_inv_on");
ui->table_drv->item(row,column++)->setText("(2)err_summ");
ui->table_drv->item(row,column++)->setText("(3)e_udover");
ui->table_drv->item(row,column++)->setText("(4)e2_uvt24");
ui->table_drv->item(row,column++)->setText("(5)e2_uvt13");
ui->table_drv->item(row,column++)->setText("(6)err_d_link");
ui->table_drv->item(row,column++)->setText("(7)o_vs_podp");
ui->table_drv->item(row,column++)->setText("(8)e2_o_vs_main");
ui->table_drv->item(row,column++)->setText("(9)err_sinc");
ui->table_drv->item(row,column++)->setText("(10)err_in_t_max");
ui->table_drv->item(row,column++)->setText("(11)err_us_low");
ui->table_drv->item(row,column++)->setText("(12)err_udover");
ui->table_drv->item(row,column++)->setText("(13)err_termodat");
ui->table_drv->item(row,column++)->setText("(14)err_dattoka");
ui->table_drv->item(row,column++)->setText("(15)err");

for(int u=0; u<72; u++){
    row++;column=0;
    QString text=QString::number(u);
    ui->table_drv->item(row,column)->setText("modstat["+text+"]");
    int mask=arhiveu8_32.arhive_data.tconv_data_stop[0].tconv_data.modstat[u];
    for(column=1; column<17; column++){
        cell = QString::number( mask & 1,2);
        ui->table_drv->item(row,column)->setText(cell);
        mask>>=1;
    }
}
row++; column=0;
ui->table_drv->item(row,column++)->setText("modstat_start");
ui->table_drv->item(row,column++)->setText("(0)not m2r");
ui->table_drv->item(row,column++)->setText("(1)e2_inv_on");
ui->table_drv->item(row,column++)->setText("(2)err_summ");
ui->table_drv->item(row,column++)->setText("(3)e_udover");
ui->table_drv->item(row,column++)->setText("(4)e2_uvt24");
ui->table_drv->item(row,column++)->setText("(5)e2_uvt13");
ui->table_drv->item(row,column++)->setText("(6)err_d_link");
ui->table_drv->item(row,column++)->setText("(7)o_vs_podp");
ui->table_drv->item(row,column++)->setText("(8)e2_o_vs_main");
ui->table_drv->item(row,column++)->setText("(9)err_sinc");
ui->table_drv->item(row,column++)->setText("(10)err_in_t_max");
ui->table_drv->item(row,column++)->setText("(11)err_us_low");
ui->table_drv->item(row,column++)->setText("(12)err_udover");
ui->table_drv->item(row,column++)->setText("(13)err_termodat");
ui->table_drv->item(row,column++)->setText("(14)err_dattoka");
ui->table_drv->item(row,column++)->setText("(15)err");

for(int u=0; u<72; u++){
    row++;column=0;
    QString text=QString::number(u);
    ui->table_drv->item(row,column)->setText("modstat["+text+"]");
    int mask=arhiveu8_32.arhive_data.tconv_data_start[0].tconv_data.modstat[u];
    for(column=1; column<17; column++){
        cell = QString::number( mask & 1,2);
        ui->table_drv->item(row,column)->setText(cell);
        mask>>=1;
    }
}
*/
row=0;column=0;
//ui->table_ram->item(row,column)->setText(cell);
for(row=1;row<FPGA_RAM_K+1;row++)
    for(column=0;column<2;column++){
        cell = QString::number(arhiveu8_32.arhive_data.ram_data[row-1].ch_byte[1-column]);
        //Старший байт (в инте)- 0 канал (напряжение) младший - 1 канал(ток)
        if(ui->table_ram->item(row,column))
            ui->table_ram->item(row,column)->setText(cell);
    }
}



#endif // PPCH440_72_HH
