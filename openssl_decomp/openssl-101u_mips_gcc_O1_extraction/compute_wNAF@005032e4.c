
char * compute_wNAF(BIGNUM *param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  char cVar7;
  uint uVar6;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  
  if (param_1->top == 0) {
    pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(1,"ec_mult.c",0xc3);
    if (pcVar13 != (char *)0x0) {
      *pcVar13 = '\0';
      *param_3 = 1;
      return pcVar13;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x8f,0x41,"ec_mult.c",0xc5);
  }
  else {
    if (param_2 - 1 < 7) {
      cVar7 = -1;
      if (param_1->neg == 0) {
        cVar7 = '\x01';
      }
      if (param_1->d != (ulong *)0x0) {
        uVar2 = BN_num_bits(param_1);
        pcVar13 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar2 + 1,"ec_mult.c",0xe0);
        if (pcVar13 == (char *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x8f,0x41,"ec_mult.c",0xe5);
          goto LAB_00503384;
        }
        uVar11 = 1 << (param_2 & 0x1f);
        param_2 = param_2 + 1;
        uVar8 = uVar11 * 2;
        uVar12 = 0;
        uVar3 = uVar8 - 1 & *param_1->d;
        pcVar9 = pcVar13;
LAB_005034cc:
        if (uVar3 == 0) {
          if (uVar2 <= param_2) {
            if (uVar12 <= uVar2 + 1) {
              *param_3 = uVar12;
              return pcVar13;
            }
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x8f,0x44,"ec_mult.c",0x125);
            goto LAB_00503384;
          }
          cVar5 = '\0';
          iVar10 = 0;
        }
        else {
          if ((uVar3 & 1) != 0) {
            uVar6 = uVar3;
            if ((uVar3 & uVar11) == 0) {
LAB_0050356c:
              if ((int)-uVar11 < (int)uVar6) goto LAB_0050357c;
            }
            else {
              if (param_2 < uVar2) {
                uVar6 = uVar3 + uVar11 * -2;
                goto LAB_0050356c;
              }
              uVar6 = uVar3 & (int)(uVar8 - 1) >> 1;
LAB_0050357c:
              if (((int)uVar6 < (int)uVar11) && ((uVar6 & 1) != 0)) {
                cVar5 = (char)uVar6;
                if (uVar3 == uVar6) {
                  cVar5 = cVar7 * cVar5;
                  iVar10 = 0;
                  goto LAB_005034e8;
                }
                if (uVar8 == uVar3 - uVar6) {
                  cVar5 = cVar7 * cVar5;
                  iVar10 = (int)uVar8 >> 1;
                }
                else {
                  if (uVar11 != uVar3 - uVar6) {
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x8f,0x44,"ec_mult.c",0x114);
                    goto LAB_00503384;
                  }
                  cVar5 = cVar7 * cVar5;
                  iVar10 = (int)uVar11 >> 1;
                }
                goto LAB_005034e8;
              }
            }
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x8f,0x44,"ec_mult.c",0x108);
            goto LAB_00503384;
          }
          iVar10 = (int)uVar3 >> 1;
          cVar5 = '\0';
        }
LAB_005034e8:
        *pcVar9 = cVar5;
        uVar12 = uVar12 + 1;
        iVar4 = BN_is_bit_set(param_1,param_2);
        pcVar9 = pcVar9 + 1;
        uVar3 = uVar11 * iVar4 + iVar10;
        param_2 = param_2 + 1;
        if ((int)uVar8 < (int)uVar3) goto code_r0x0050351c;
        goto LAB_005034cc;
      }
      uVar1 = 0xdb;
    }
    else {
      uVar1 = 0xcf;
    }
    pcVar13 = (char *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x8f,0x44,"ec_mult.c",uVar1);
  }
  goto LAB_00503384;
code_r0x0050351c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x8f,0x44,"ec_mult.c",0x11f);
LAB_00503384:
  (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar13);
  return (char *)0x0;
}

