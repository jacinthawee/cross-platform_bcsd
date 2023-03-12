
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
    ptr = (ulong *)CRYPTO_malloc(1,"ec_mult.c",0xc3);
    iVar3 = 0xc5;
    if (ptr != (ulong *)0x0) {
      *(undefined *)ptr = 0;
      *param_3 = 1;
      return ptr;
    }
LAB_0008fd04:
    ERR_put_error(0x10,0x8f,0x41,"ec_mult.c",iVar3);
  }
  else {
    if (6 < param_2 - 1) {
      ptr = (ulong *)0x0;
      ERR_put_error(0x10,0x8f,0x44,"ec_mult.c",0xcf);
      goto LAB_0008fc98;
    }
    ptr = param_1->d;
    if (param_1->neg == 0) {
      sVar2 = 1;
    }
    else {
      sVar2 = -1;
    }
    iVar3 = 0xdb;
    if (ptr != (ulong *)0x0) {
      uVar1 = BN_num_bits(param_1);
      ptr = (ulong *)CRYPTO_malloc(uVar1 + 1,"ec_mult.c",0xe0);
      if (ptr == (ulong *)0x0) {
        iVar3 = 0xe5;
        goto LAB_0008fd04;
      }
      uVar6 = 1 << (param_2 & 0xff);
      param_2 = param_2 + 1;
      uVar8 = uVar6 * 2;
      uVar4 = uVar8 - 1 & *param_1->d;
      uVar7 = 0;
      uVar5 = uVar4;
      if (uVar4 != 0) goto LAB_0008fc48;
LAB_0008fc22:
      uVar5 = uVar4;
      if (param_2 < uVar1) {
LAB_0008fc28:
        do {
          *(char *)((int)ptr + uVar7) = (char)uVar4;
          iVar3 = BN_is_bit_set(param_1,param_2);
          param_2 = param_2 + 1;
          uVar7 = uVar7 + 1;
          uVar4 = uVar6 * iVar3 + ((int)uVar5 >> 1);
          if ((int)uVar8 < (int)uVar4) {
            iVar3 = 0x11f;
            goto LAB_0008fc88;
          }
          uVar5 = uVar4;
          if (uVar4 == 0) goto LAB_0008fc22;
LAB_0008fc48:
          uVar4 = uVar5 & 1;
          if (uVar4 != 0) {
            uVar4 = uVar5;
            if ((uVar5 & uVar6) == 0) {
LAB_0008fcee:
              if ((int)-uVar6 < (int)uVar4) goto LAB_0008fc60;
            }
            else {
              if (param_2 < uVar1) {
                uVar4 = uVar5 + uVar6 * -2;
                goto LAB_0008fcee;
              }
              uVar4 = (int)(uVar8 - 1) >> 1 & uVar5;
LAB_0008fc60:
              if (((int)uVar4 < (int)uVar6) && ((int)(uVar4 << 0x1f) < 0)) {
                uVar5 = uVar5 - uVar4;
                if ((uVar5 != uVar8 && uVar5 != 0) && (uVar5 != uVar6)) {
                  iVar3 = 0x114;
                  goto LAB_0008fc88;
                }
                uVar4 = (int)(short)uVar4 * (int)sVar2 & 0xff;
                goto LAB_0008fc28;
              }
            }
            iVar3 = 0x108;
            goto LAB_0008fc88;
          }
        } while( true );
      }
      if (uVar7 <= uVar1 + 1) {
        *param_3 = uVar7;
        return ptr;
      }
      iVar3 = 0x125;
    }
LAB_0008fc88:
    ERR_put_error(0x10,0x8f,0x44,"ec_mult.c",iVar3);
  }
LAB_0008fc98:
  CRYPTO_free(ptr);
  return (ulong *)0x0;
}

