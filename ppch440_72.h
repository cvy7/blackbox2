#ifndef PPCH440_72_H
#define PPCH440_72_H
/*
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QFile>
*/
//#include <inttypes.h>
#define FPGA_RAM_K 12801
#define MAX_REGS 124

#pragma pack(push, 1)

typedef struct {
         unsigned short res_err   :1,// сброс ошибки
                  inv_on        :1,// команда включить инвертор
                  pow_mod       :1,// включиь диагностику питания модулей
                  regulator     :1,// включить регулирование/ иначе ручной режим задания  выходного напряжения
                  pll           :1,// включить ФАПЧ/ иначе ручной режим управления частотой
                  ud            :1,// включить диагностику по UD- как минимум так и максимум
                  em_stop       :1,// реагировать на нажатие аварийного стопа
                  uo            :1,// реагировать на превышение выходного напряжения
                  io            :1,// реагировать на превышение выходного тока
                  conn_mod      :1,// реагировать на ошибки связи
                  fo            :1,// частота в допустимых пределах
                  r11           :1,//
                  id            :1,// реагировать на входной  ток
                  rvpr          :1,// разрешение включения выпрямителя
                  mod           :1,// КЗ через горизонталь инвертора в паузах
                  global_on     :1;//реагировать на любую ошибку, как и в предыдущих случаях БИТ ОШИБКИ БУДЕТ ВЫСТАВЛЯТЬСЯ,
                                   //но реакции СТОП и ДЕШИФРАЦИИ НЕ БУДЕТ.
               } tdiags;
//65535 =-1 все включено
//0 все выключено
//1111111111100100=65508 regulator=0 pll=0
//1111111111110100=65524 regulator=0
//1111111111101100=65516 pll=0
//1011111111111100=49148 kzp=0

#define DIAG_MOD 4
#define DIAG_REGULATOR 8
#define DIAG_PLL 16
#define DIAG_UD 32
#define DIAG_EM_STOP 64
#define DIAG_UO 128
#define DIAG_IO 256
#define DIAG_CONN 512
#define DIAG_FO 1024
#define DIAG_R11 2048
#define DIAG_ID 4096
#define DIAG_RVPR 8192
#define DIAG_KZP 16384
#define DIAG_GLOBAL_ON 32768
#define ERR_MAX 4

typedef struct {
  unsigned short      err             :1,//общая ошибка
                    err_emer_stop   :1,// нажат аварийный стоп
                    err_uo_max      :1,// напряжение на выходе ППЧ выше допустимого
                    err_io_maxc     :1,// превышение коммутационного тока
                    err_io_max      :1,// ток на выходе ППЧ выше допустимого
                    err_fo_min      :1,// частота колебательного контура ниже минимально-допустимой
                    err_fo_max      :1,// частота колебательного контура выше максимально допустимой
                    err_mod         :1,// общая ошибка подключенных модулей
                    err_id_max      :1,// превышение входного тока
                    reg_uo          :1,
                    reg_io          :1,
                    pll_fo_not_lock :1,
                    err_mosi        :1,
                    reg_not_in_limit:1,
                    err_con         :1,// ошибка приема от модулей
                    err_pow         :1;// ошибка питания модулей
               } tplst;

typedef struct {
  unsigned short    not_m2r         :1,//Модуль не в резерве
                    e2_inv_on       :1,//
                    err_mod_summ    :1,// Общая ошибка собранная со всех модулей для ускорения связи
                    e_udover        :1,//
                    e2_uvt24        :1,// Напряжение на транзисторах
                    e2_uvt13        :1,// Напряжение на транзисторах
                    err_d_link      :1,// Ошибка связи в сторону модуля - некорректный импульс
                    o_vs_podp       :1,// Выход включения тиристора подпитки -используется для формирования имп вкл и контр связи
                    e2_o_vs_main    :1,// Выход включения основного тиристора- используется для контроля связи
                    err_sinc        :1,// Ош синхр- только для отл.
                    err_in_t_max    :1,// Ош макс врем.- только для отл.
                    err_us_low      :1,// Низкое напряжение питания драйвера
                    err_udover      :1,// Превышено напряжение
                    err_termodat    :1,// Ошибка по термодатчику плюс контроль наводок
                    err_dattoka     :1,// Ошибка по току
                    err             :1;// ошибка модуля
               } tmodst;

typedef struct {
    unsigned short  heat_on         :1,// Нагрев включен
                  command_heat_on :1,// Команда включить нагрев
                  ready           :1,// Готовность преобразователя
                  command_ready   :1,// Команда привести в готовность преобразователь- можно выдать сразу- тогда ППЧ сразу включит контакторы
                                     // ТПЧ - возможно взводиьть автомат вручную- если без привода
                  err             :1,// Ошибка преобразователя (для ППЧ по сути предупреждение- преобразователь работает при этом)
                  bloked          :1,// Фатальная ошибка преобразователя- отключен
                  conn_err        :1,// Ошибка связи с преобразователем
                  command_reset   :1,// Команда сбросить ошибки- аналогична команде ready
        //--------------------------------------

                  switch_on       :1,// Автомат включен- заполняется ТПЧ/ для ППЧ- это charge
                  err_so          :1,// Ошибка Станции охлаждения - заполняется ТПЧ, если датчики протока подключены к ТПЧ, а не напрямую к Сименсу0
                  err_bk          :1,// Ошибка по датчикам Блока Компенсации - аналогично ошибке СО
                  mestnoe_upr     :1,// Ключ на преобразователе переведен в местный режим
                  so_on           :1,// Станция охлаждения включена- опять же если используется канал Сименс->ТПЧ->СО, если напрямую- то напрямую
                  pusk_so         :1,// Команда включить станцию охлаждения
                  heartbeat       :1,//
                  r15             :1; //@mb_300
            } tconvb;

typedef union{
            tconvb convb;
    unsigned short convs;
} tconvbu;

typedef union{
            tdiags diagsb;
    unsigned short diagss;
} tdiagsu;

typedef union{
            tplst  plstb;
    unsigned short plsts;
} tplstu;

typedef struct {
              tconvbu        convb;//@mb_300
              tdiagsu        diags;//@mb_301
              tplstu         plst;//@mb_302
              unsigned short P;                 // Измеренная мощность //@mb_303
              unsigned short ps;                // Заданная мощность //@mb_304
              unsigned int   fou;              ////@mb_305-306 Частота выходного напряжения (либо результат анализа нагрузки, если ошибка по частоте ППЧ)
              unsigned short  fo_min;           //@mb_307
              unsigned short  fo_norm;          //@mb_308
              unsigned short  fo_max;           //@mb_309
              unsigned short  co;               //@mb_310
              unsigned short  cs;               //@mb_311
              unsigned short  id;               //@mb_312  // Выпрямленный ток в А
              unsigned short  id_max;           //@mb_313
              unsigned short  ki_id;            //@mb_314
              unsigned short  iou;              //@mb_315 // Выходной ток в А- в ТПЧ равен выпрямленному
              unsigned short  is;               //@mb_316
              unsigned short  io_max;           //@mb_317
              unsigned short  io_maxc;          //@mb_318
              unsigned short  ki_io;            //@mb_319
              unsigned short  uou;              //@mb_320 // Напряжение Выходное преобразователя
              unsigned short  us;               //@mb_321
              unsigned short  uo_max;           //@mb_322
              unsigned short  ki_uo;            //@mb_323
              unsigned short  ud;               //@mb_324
              unsigned short  ud_min;           //@mb_325
              unsigned short  ud_max;           //@mb_326
              unsigned short  ki_ud;            //@mb_327
              unsigned char t_water;          //@mb_328 +t[0] // Температура воды на входе t[1]-t[2] 329 t3-t4 330 t5-t6 331 t7-t8 332 t9-t10 333
              unsigned char t[32];            // Температура 0 датчика- зависит от применения t11-t12 334 t13-t14 335 t15-t16 336 t17=t18 337 t19-t20 338
              unsigned char t_max;            // Максимальная Температура                     t21-t22 339 t23-t24 340 t25-t26 341 t27-t27 342 t29-T30 343
                                              //                                              t31-tmax 344
              unsigned char t_maxp;           //@mb_345
              unsigned char rashod;           // Расход воды по данным расходомера в преобразователе
              unsigned short  err_cod[ERR_MAX]; // 346 347 348 349 Код ошибки
              unsigned short  doors;            //350
              unsigned short  wtr;              //351
              unsigned short  io_2k;            //352
              unsigned short  uo_2k;            //353
              unsigned short  ioc;              //354
              unsigned short  uop;              //355 пусковое напряжение
              unsigned short  psp;              //356 пусковая мощность
              unsigned short  nmp;              //357 пусковой К инвертора
              unsigned short  nmd;              //358
              unsigned short  us2;              //359
              unsigned short  ps2;              //360
              unsigned short  usstep;           //361
              unsigned short  psstep;           //362
              unsigned short  kpup;             //363
              unsigned short  kppp;             //364
              unsigned short  kiup;             //365
              unsigned short  kipp;             //366
              unsigned short  nmx;              //367
              short           udf[8];           //368.369.370.371.372.373.374.375
              unsigned short  proto0;           //376
              unsigned short  proto1;           //377
              unsigned short  k_rec;            //378
              unsigned short  vp;               //379
              unsigned short  vpp;              //380
              unsigned short  tvp;              //381
                       short  psv;              //382
              unsigned short  uo_max0;          //383
              unsigned short  uo_max2;          //384
              unsigned short  io_max0;          //385
              unsigned short  par0;             //386
              unsigned short  par1;             //387
              unsigned short  sinc;             //388
              unsigned short  modstat[72];      //389..460
              unsigned short  err_parity[5];    //461..465
              unsigned short  err_power[5];     //466..470
              unsigned short  mod_mask[5];      //471..475
              unsigned short  fou_aic;          //476
              unsigned short  dvr;              //477
              unsigned short  kpu;              //478
              unsigned short  kiu;              //479
              unsigned short  kpp;              //480
              unsigned short  kip;              //481
              unsigned short  kn ;              //482
              unsigned short  f_sel ;           //483
              unsigned short  io_max1;          //484
              } tconv;

typedef union {
    tconv tconv_data;
    unsigned char tconv_bytes[512];
} tconvu;

typedef struct {
    signed char ch_byte[2];
               } tram;

typedef struct {
    unsigned char str_start[16];//tconv_start****
    tconvu tconv_data_start[16];
    unsigned char str_stop[16]; //tconv_stop*****
    tconvu tconv_data_stop[16];
    unsigned char str_ram[16];  //fpga_ram*******
    tram ram_data[FPGA_RAM_K];
               } tarhiv;

typedef union{
    tarhiv arhive_data;
    unsigned char arhive_bytes[sizeof(tarhiv)];
} tarhivu;
/*


class Ppch440_72: public QObject
{
public:
    Ppch440_72();
    ~Ppch440_72();
    void load_arhive(QFile *arhive);

    Q_OBJECT
tarhiv arhive_data;


};*/
#pragma pack(pop)
#endif // PPCH440_72_H
