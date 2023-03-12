
void show_ciphers(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
  if ((*(ushort *)(*piVar1 + (uint)**(byte **)(param_1 + 8) * 2) & 2) != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_2,"-%-25s");
    n_16255 = n_16255 + 1;
    if (n_16255 != 3) {
                    /* WARNING: Could not recover jumptable at 0x0042b2a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_printf_006a6e38)(param_2,&DAT_0063eb84);
      return;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(param_2,"\n");
    n_16255 = 0;
  }
  return;
}

