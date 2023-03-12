
undefined * __regparm3 compute_wNAF(BIGNUM *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined *ptr;
  int iVar9;
  
  if (param_1->top == 0) {
    ptr = (undefined *)CRYPTO_malloc(1,"ec_mult.c",0xcc);
    if (ptr != (undefined *)0x0) {
      *ptr = 0;
      *param_3 = 1;
      return ptr;
    }
    iVar9 = 0xcf;
LAB_081028f8:
    ERR_put_error(0x10,0x8f,0x41,"ec_mult.c",iVar9);
  }
  else {
    if (param_2 - 1 < 7) {
      iVar9 = param_1->neg;
      if (param_1->d != (ulong *)0x0) {
        uVar3 = BN_num_bits(param_1);
        ptr = (undefined *)CRYPTO_malloc(uVar3 + 1,"ec_mult.c",0xec);
        if (ptr != (undefined *)0x0) {
          uVar4 = 1 << ((byte)param_2 & 0x1f);
          uVar1 = uVar4 * 2;
          uVar7 = *param_1->d & uVar1 - 1;
          uVar8 = 0;
          do {
            param_2 = param_2 + 1;
            if (uVar7 == 0) {
              if (uVar3 <= param_2) {
                if (uVar8 <= uVar3 + 1) {
                  *param_3 = uVar8;
                  return ptr;
                }
                iVar9 = 0x135;
                goto LAB_081028ac;
              }
LAB_081027fe:
              cVar2 = '\0';
            }
            else {
              if ((uVar7 & 1) == 0) goto LAB_081027fe;
              uVar6 = uVar7;
              if ((uVar7 & uVar4) == 0) {
LAB_08102855:
                if ((int)-uVar4 < (int)uVar6) goto LAB_0810285b;
LAB_081028a0:
                iVar9 = 0x117;
                goto LAB_081028ac;
              }
              if (param_2 < uVar3) {
                uVar6 = uVar7 + uVar4 * -2;
                goto LAB_08102855;
              }
              uVar6 = (int)(uVar1 - 1) >> 1 & uVar7;
LAB_0810285b:
              if (((int)uVar4 <= (int)uVar6) || ((uVar6 & 1) == 0)) goto LAB_081028a0;
              uVar7 = uVar7 - uVar6;
              if ((uVar7 != 0 && uVar1 != uVar7) && (uVar4 != uVar7)) {
                iVar9 = 0x122;
                goto LAB_081028ac;
              }
              cVar2 = (char)uVar6 * ((-(iVar9 == 0) & 2U) - 1);
            }
            ptr[uVar8] = cVar2;
            iVar5 = BN_is_bit_set(param_1,param_2);
            uVar7 = iVar5 * uVar4 + ((int)uVar7 >> 1);
            uVar8 = uVar8 + 1;
          } while ((int)uVar7 <= (int)uVar1);
          iVar9 = 0x12e;
LAB_081028ac:
          ERR_put_error(0x10,0x8f,0x44,"ec_mult.c",iVar9);
          goto LAB_0810270a;
        }
        iVar9 = 0xf1;
        goto LAB_081028f8;
      }
      iVar9 = 0xe7;
    }
    else {
      iVar9 = 0xd9;
    }
    ptr = (undefined *)0x0;
    ERR_put_error(0x10,0x8f,0x44,"ec_mult.c",iVar9);
  }
LAB_0810270a:
  CRYPTO_free(ptr);
  return (undefined *)0x0;
}

