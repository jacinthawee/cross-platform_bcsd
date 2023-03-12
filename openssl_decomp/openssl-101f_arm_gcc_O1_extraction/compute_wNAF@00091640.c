
ulong * compute_wNAF(BIGNUM *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong *ptr;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_1->top == 0) {
    ptr = (ulong *)CRYPTO_malloc(1,"ec_mult.c",0xcc);
    iVar3 = 0xcf;
    if (ptr != (ulong *)0x0) {
      *(undefined *)ptr = 0;
      *param_3 = 1;
      return ptr;
    }
LAB_000917a4:
    ERR_put_error(0x10,0x8f,0x41,"ec_mult.c",iVar3);
  }
  else {
    if (6 < param_2 - 1) {
      ptr = (ulong *)0x0;
      ERR_put_error(0x10,0x8f,0x44,"ec_mult.c",0xd9);
      goto LAB_00091738;
    }
    ptr = param_1->d;
    if (param_1->neg == 0) {
      sVar2 = 1;
    }
    else {
      sVar2 = -1;
    }
    iVar3 = 0xe7;
    if (ptr != (ulong *)0x0) {
      uVar1 = BN_num_bits(param_1);
      ptr = (ulong *)CRYPTO_malloc(uVar1 + 1,"ec_mult.c",0xec);
      if (ptr == (ulong *)0x0) {
        iVar3 = 0xf1;
        goto LAB_000917a4;
      }
      uVar6 = 1 << (param_2 & 0xff);
      param_2 = param_2 + 1;
      uVar8 = uVar6 * 2;
      uVar4 = uVar8 - 1 & *param_1->d;
      uVar7 = 0;
      uVar5 = uVar4;
      if (uVar4 != 0) goto LAB_000916e8;
LAB_000916c2:
      uVar5 = uVar4;
      if (param_2 < uVar1) {
LAB_000916c8:
        do {
          *(char *)((int)ptr + uVar7) = (char)uVar4;
          iVar3 = BN_is_bit_set(param_1,param_2);
          param_2 = param_2 + 1;
          uVar7 = uVar7 + 1;
          uVar4 = uVar6 * iVar3 + ((int)uVar5 >> 1);
          if ((int)uVar8 < (int)uVar4) {
            iVar3 = 0x12e;
            goto LAB_00091728;
          }
          uVar5 = uVar4;
          if (uVar4 == 0) goto LAB_000916c2;
LAB_000916e8:
          uVar4 = uVar5 & 1;
          if (uVar4 != 0) {
            uVar4 = uVar5;
            if ((uVar5 & uVar6) == 0) {
LAB_0009178e:
              if ((int)-uVar6 < (int)uVar4) goto LAB_00091700;
            }
            else {
              if (param_2 < uVar1) {
                uVar4 = uVar5 + uVar6 * -2;
                goto LAB_0009178e;
              }
              uVar4 = (int)(uVar8 - 1) >> 1 & uVar5;
LAB_00091700:
              if (((int)uVar4 < (int)uVar6) && ((int)(uVar4 << 0x1f) < 0)) {
                uVar5 = uVar5 - uVar4;
                if ((uVar5 != uVar8 && uVar5 != 0) && (uVar5 != uVar6)) {
                  iVar3 = 0x122;
                  goto LAB_00091728;
                }
                uVar4 = (int)(short)uVar4 * (int)sVar2 & 0xff;
                goto LAB_000916c8;
              }
            }
            iVar3 = 0x117;
            goto LAB_00091728;
          }
        } while( true );
      }
      if (uVar7 <= uVar1 + 1) {
        *param_3 = uVar7;
        return ptr;
      }
      iVar3 = 0x135;
    }
LAB_00091728:
    ERR_put_error(0x10,0x8f,0x44,"ec_mult.c",iVar3);
  }
LAB_00091738:
  CRYPTO_free(ptr);
  return (ulong *)0x0;
}

