
undefined4 __regparm3
do_i2r_name_constraints_isra_1(_STACK *param_1_00,BIO *param_2,int param_3,undefined4 param_1)

{
  ushort uVar1;
  GENERAL_NAME *gen;
  stack_st_X509_NAME_ENTRY *psVar2;
  BUF_MEM *pBVar3;
  int iVar4;
  GENERAL_NAME **ppGVar5;
  int iVar6;
  int local_28;
  
  iVar4 = sk_num(param_1_00);
  if (0 < iVar4) {
    BIO_printf(param_2,"%*s%s:\n",param_3,&DAT_081eca46,param_1);
  }
  local_28 = 0;
  do {
    iVar4 = sk_num(param_1_00);
    if (iVar4 <= local_28) {
      return 1;
    }
    ppGVar5 = (GENERAL_NAME **)sk_value(param_1_00,local_28);
    BIO_printf(param_2,"%*s",param_3 + 2,&DAT_081eca46);
    gen = *ppGVar5;
    if (gen->type == 7) {
      psVar2 = ((gen->d).directoryName)->entries;
      pBVar3 = ((gen->d).directoryName)->bytes;
      BIO_puts(param_2,"IP:");
      if (psVar2 == (stack_st_X509_NAME_ENTRY *)0x8) {
        BIO_printf(param_2,"%d.%d.%d.%d/%d.%d.%d.%d",(uint)*(byte *)&pBVar3->length,
                   (uint)*(byte *)((int)&pBVar3->length + 1),
                   (uint)*(byte *)((int)&pBVar3->length + 2),
                   (uint)*(byte *)((int)&pBVar3->length + 3),(uint)*(byte *)&pBVar3->data,
                   (uint)*(byte *)((int)&pBVar3->data + 1),(uint)*(byte *)((int)&pBVar3->data + 2),
                   (uint)*(byte *)((int)&pBVar3->data + 3));
      }
      else {
        if (psVar2 == (stack_st_X509_NAME_ENTRY *)0x20) {
          iVar4 = 1;
          iVar6 = 0;
          do {
            uVar1 = *(ushort *)((int)&pBVar3->length + iVar6 * 2);
            BIO_printf(param_2,"%X",(uint)(ushort)(uVar1 << 8 | uVar1 >> 8));
            if (iVar6 == 7) {
              BIO_puts(param_2,"/");
            }
            else {
              if (iVar6 == 0xf) goto LAB_0817407d;
              BIO_puts(param_2,":");
              if (iVar4 == 0x10) goto LAB_0817407d;
            }
            iVar6 = iVar6 + 1;
            iVar4 = iVar4 + 1;
          } while( true );
        }
        BIO_printf(param_2,"IP Address:<invalid>");
      }
    }
    else {
      GENERAL_NAME_print(param_2,gen);
    }
LAB_0817407d:
    BIO_puts(param_2,"\n");
    local_28 = local_28 + 1;
  } while( true );
}

