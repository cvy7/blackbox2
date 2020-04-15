#ifndef CONV_H
#define CONV_H

#define ERR_MAX 4

typedef struct {
         unsigned int res_err   :1,// сброс ошибки
                  inv_on        :1,// команда включить инвертор
                  diag_mod      :1,// включиь диагностику модулей
                  regulator     :1,// включить регулирование/ иначе ручной режим задания  выходного напряжения
                  pll           :1,// включить ФАПЧ/ иначе ручной режим управления частотой
                  ud            :1,// включить диагностику по UD- как минимум так и максимум
                  em_stop       :1,// реагировать на нажатие аварийного стопа
                  uo            :1,// реагировать на превышение выходного напряжения
                  io            :1,// реагировать на превышение выходного тока
                  conn          :1,// реагировать на ошибки связи и отсутствие питания модулей
                  fo            :1,// частота в допустимых пределах
                  r11           :1,//
                  id            :1,// реагировать на входной  ток
                  rvpr          :1,// разрешение включения выпрямителя
                  kzp           :1,// КЗ через горизонталь инвертора в паузах
                  global_on     :1;//реагировать на любую ошибку, как и в предыдущих случаях БИТ ОШИБКИ БУДЕТ ВЫСТАВЛЯТЬСЯ,
                                   //но реакции СТОП и ДЕШИФРАЦИИ НЕ БУДЕТ.
               } tdiags;
//65535 =-1 все включено
//0 все выключено
//1111111111100100=65508 regulator=0 pll=0
//1111111111110100=65524 regulator=0
//1111111111101100=65516 pll=0
//1011111111111100=49148 kzp=0

typedef struct {
  unsigned int      err             :1,//общая ошибка
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
                    r12             :1,
                    reg_not_in_limit:1,
                    r14             :1,
                    e_off           :1;// ошибка, при которой надо вырубатть питание
               } tplst;

typedef struct {
              unsigned int  heat_on         :1,// Нагрев включен
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

              tdiags        diags;//@mb_301
              tplst         plst;//@mb_302
              unsigned int P;                 // Измеренная мощность //@mb_303
              unsigned int ps;                // Заданная мощность //@mb_304
              unsigned long fou;              ////@mb_305-306 Частота выходного напряжения (либо результат анализа нагрузки, если ошибка по частоте ППЧ)
              unsigned int  fo_min;           //@mb_307
              unsigned int  fo_norm;          //@mb_308
              unsigned int  fo_max;           //@mb_309
              unsigned int  co;               //@mb_310
              unsigned int  cs;               //@mb_311
              unsigned int  id;               //@mb_312  // Выпрямленный ток в А
              unsigned int  id_max;           //@mb_313
              unsigned int  ki_id;            //@mb_314
              unsigned int  iou;              //@mb_315 // Выходной ток в А- в ТПЧ равен выпрямленному
              unsigned int  is;               //@mb_316
              unsigned int  io_max;           //@mb_317
              unsigned int  io_maxc;          //@mb_318
              unsigned int  ki_io;            //@mb_319
              unsigned int  uou;              //@mb_320 // Напряжение Выходное преобразователя
              unsigned int  us;               //@mb_321
              unsigned int  uo_max;           //@mb_322
              unsigned int  ki_uo;            //@mb_323
              unsigned int  ud;               //@mb_324
              unsigned int  ud_min;           //@mb_325
              unsigned int  ud_max;           //@mb_326
              unsigned int  ki_ud;            //@mb_327
              unsigned char  t_water;         ////@mb_328 +t[0] // Температура воды на входе t[1]-t[2] 329 t3-t4 330 t5-t6 331 t7-t8 332 t9-tmax 333
              unsigned char  t[10];           // Температура 0 датчика- зависит от применения
              unsigned char  t_max;           // Максимальная Температура
              unsigned char  t_maxp;          //@mb_334
              unsigned char  rashod;            // Расход воды по данным расходомера в преобразователе
              unsigned int  err_cod[ERR_MAX];  // 335 336 337 338 Код ошибки
              unsigned int  doors;            //339
              unsigned int  wtr;              //340
              unsigned int  io_2k;            //341
              unsigned int  uo_2k;            //342
              unsigned int  ioc;              //343
              unsigned int  uop;              // 344 пусковое напряжение
              unsigned int  psp;               //345 пусковая мощность
              unsigned int  nmp;               //346 пусковой К инвертора
              unsigned int  nmd;               // 347
              unsigned int  us2;              //348
              unsigned int  ps2;              //349
              unsigned int  usstep;           //350
              unsigned int  psstep;           //351
              unsigned int  kpup;             //352
              unsigned int  kppp;             //353
              unsigned int  kiup;             //354
              unsigned int  kipp;             //355
              unsigned int  nmx;              //356
              int udf[8];                     //357.358.359.360.361.362.363.364
              unsigned int  proto0;           //365
              unsigned int  proto1;           //366
              unsigned int  k_rec;            //367
              unsigned int  vp;               //368
              unsigned int  vpp;              //369
              unsigned int  tvp;              //370
                       int  psv;              //371
              unsigned int  uo_max0;          //372
              unsigned int  uo_max2;          //373
              unsigned int  io_max0;          //374

//                       int  psv2;
              } tconv;

void CONV_poll(void);
void CONV_err_print(void);
void CONV_reset(void);
void CONV_reset0(void);
void CONV_heat_on(void);
void CONV_heat_off(void);
void CONV_ready(void);
void CONV_off(void);
extern unsigned char conv_timeout;
extern unsigned char conv_start_tx;
extern tconv conv;
extern signed char CONV_state;
//extern tdiags diags;
//extern tplst plst;

#define CONV_ERR_OFF  (-1)
#define CONV_OFF      (0 )
#define CONV_CHARGE   (5 )
#define CONV_CHARGE1  (6 )
#define CONV_CHARGE2  (7 )
#define CONV_ERR_ON   (8 )
#define CONV_READY    (10)
#define CONV_HEAT_ON1 (17)
#define CONV_HEAT_ON15 (18)
#define CONV_HEAT_ON2 (19)
#define CONV_HEAT_ON  (20)

#endif // CONV_H
