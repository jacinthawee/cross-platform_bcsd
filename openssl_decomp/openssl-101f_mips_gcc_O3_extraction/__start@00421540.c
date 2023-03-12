
void __start(void)

{
  undefined4 local_res0;
  undefined auStackX_4 [12];
  undefined auStack_20 [16];
  undefined *local_10;
  undefined *local_8;
  
  local_8 = auStack_20;
  local_10 = PTR___libc_csu_fini_006a7f00;
  (*(code *)PTR___libc_start_main_006aab2c)
            (PTR_main_006a7ef8,local_res0,auStackX_4,PTR___libc_csu_init_006a7efc);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

