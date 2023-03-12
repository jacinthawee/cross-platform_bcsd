
undefined4 ssl_prepare_clienthello_tlsext(SSL *param_1)

{
  _STACK *p_Var1;
  void *pvVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  int *piVar6;
  undefined uVar7;
  int iVar8;
  
  p_Var1 = (_STACK *)SSL_get_ciphers(param_1);
  iVar8 = 0;
  do {
    iVar3 = sk_num(p_Var1);
    if (iVar3 <= iVar8) {
      return 1;
    }
    pvVar2 = sk_value(p_Var1,iVar8);
  } while (((*(uint *)((int)pvVar2 + 0xc) & 0xe0) == 0) &&
          (iVar8 = iVar8 + 1, -1 < *(int *)((int)pvVar2 + 0x10) << 0x19));
  if (0x300 < param_1->version) {
    if ((void *)param_1->tlsext_ecpointformatlist_length != (void *)0x0) {
      CRYPTO_free((void *)param_1->tlsext_ecpointformatlist_length);
    }
    puVar4 = (undefined *)CRYPTO_malloc(3,"t1_lib.c",0x6c3);
    param_1->tlsext_ecpointformatlist_length = (size_t)puVar4;
    if (puVar4 == (undefined *)0x0) {
      ERR_put_error(0x14,0x119,0x41,"t1_lib.c",0x6c5);
      return 0xffffffff;
    }
    param_1->tlsext_ticket_expected = 3;
    *puVar4 = 0;
    *(undefined *)(param_1->tlsext_ecpointformatlist_length + 1) = 1;
    *(undefined *)(param_1->tlsext_ecpointformatlist_length + 2) = 2;
    if ((void *)param_1->tlsext_ellipticcurvelist_length != (void *)0x0) {
      CRYPTO_free((void *)param_1->tlsext_ellipticcurvelist_length);
    }
    param_1->tlsext_ecpointformatlist = (uchar *)0x32;
    puVar4 = (undefined *)CRYPTO_malloc(0x32,"t1_lib.c",0x6d5);
    param_1->tlsext_ellipticcurvelist_length = (size_t)puVar4;
    if (puVar4 == (undefined *)0x0) {
      param_1->tlsext_ecpointformatlist = (uchar *)0x0;
      ERR_put_error(0x14,0x119,0x41,"t1_lib.c",0x6d8);
      return 0xffffffff;
    }
    piVar5 = (int *)(PTR_DAT_00053a10 + 100);
    piVar6 = (int *)PTR_DAT_00053a10;
    do {
      piVar6 = piVar6 + 1;
      iVar8 = *piVar6;
      if (iVar8 == 0x2d2) {
        uVar7 = 2;
      }
      else if (iVar8 < 0x2d3) {
        if (iVar8 == 0x2c7) {
          uVar7 = 0x12;
        }
        else if (iVar8 < 0x2c8) {
          if (iVar8 == 0x2c4) {
            uVar7 = 0xf;
          }
          else if (iVar8 < 0x2c5) {
            if (iVar8 == 0x199) {
              uVar7 = 0x13;
            }
            else {
              if (iVar8 != 0x19f) goto LAB_00053914;
              uVar7 = 0x17;
            }
          }
          else if (iVar8 == 0x2c5) {
            uVar7 = 0x10;
          }
          else {
            if (iVar8 != 0x2c6) goto LAB_00053914;
            uVar7 = 0x11;
          }
        }
        else if (iVar8 == 0x2ca) {
          uVar7 = 0x16;
        }
        else if (iVar8 < 0x2cb) {
          if (iVar8 == 0x2c8) {
            uVar7 = 0x14;
          }
          else {
            if (iVar8 != 0x2c9) goto LAB_00053914;
            uVar7 = 0x15;
          }
        }
        else if (iVar8 == 0x2cc) {
          uVar7 = 0x19;
        }
        else if (iVar8 < 0x2cc) {
          uVar7 = 0x18;
        }
        else {
          if (iVar8 != 0x2d1) goto LAB_00053914;
          uVar7 = 1;
        }
      }
      else if (iVar8 == 0x2d8) {
        uVar7 = 8;
      }
      else if (iVar8 < 0x2d9) {
        if (iVar8 == 0x2d5) {
          uVar7 = 5;
        }
        else if (iVar8 < 0x2d6) {
          if (iVar8 == 0x2d3) {
            uVar7 = 3;
          }
          else if (iVar8 == 0x2d4) {
            uVar7 = 4;
          }
          else {
LAB_00053914:
            uVar7 = 0;
          }
        }
        else if (iVar8 == 0x2d6) {
          uVar7 = 6;
        }
        else {
          if (iVar8 != 0x2d7) goto LAB_00053914;
          uVar7 = 7;
        }
      }
      else if (iVar8 == 0x2db) {
        uVar7 = 0xb;
      }
      else if (iVar8 < 0x2dc) {
        if (iVar8 == 0x2d9) {
          uVar7 = 9;
        }
        else {
          if (iVar8 != 0x2da) goto LAB_00053914;
          uVar7 = 10;
        }
      }
      else if (iVar8 == 0x2dd) {
        uVar7 = 0xd;
      }
      else if (iVar8 < 0x2dd) {
        uVar7 = 0xc;
      }
      else {
        if (iVar8 != 0x2de) goto LAB_00053914;
        uVar7 = 0xe;
      }
      *puVar4 = 0;
      puVar4[1] = uVar7;
      puVar4 = puVar4 + 2;
    } while (piVar6 != piVar5);
  }
  return 1;
}

