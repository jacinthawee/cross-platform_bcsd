
void show_ciphers(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
  if ((*(ushort *)(*piVar1 + (uint)**(byte **)(param_1 + 8) * 2) & 2) != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_2,"-%-25s");
    n_16245 = n_16245 + 1;
    if (n_16245 != 3) {
                    /* WARNING: Could not recover jumptable at 0x0042b210. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_printf_006a7f38)(param_2,&DAT_0063f0b8);
      return;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(param_2,"\n");
    n_16245 = 0;
  }
  return;
}

