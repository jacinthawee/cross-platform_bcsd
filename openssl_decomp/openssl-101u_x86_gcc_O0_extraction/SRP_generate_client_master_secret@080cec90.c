
undefined4 SRP_generate_client_master_secret(int param_1,undefined4 param_2)

{
  int iVar1;
  BIGNUM *a;
  char *__s;
  BIGNUM *a_00;
  BIGNUM *a_01;
  int iVar2;
  uchar *to;
  undefined4 uVar3;
  size_t sVar4;
  
  iVar1 = SRP_Verify_B_mod_N(*(undefined4 *)(param_1 + 0x1b4),*(undefined4 *)(param_1 + 0x1a8));
  if (iVar1 == 0) {
LAB_080cee20:
    a = (BIGNUM *)0x0;
  }
  else {
    a = (BIGNUM *)
        SRP_Calc_u(*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1b4),
                   *(undefined4 *)(param_1 + 0x1a8));
    if (a == (BIGNUM *)0x0) goto LAB_080cee20;
    if (*(code **)(param_1 + 0x1a0) != (code *)0x0) {
      __s = (char *)(**(code **)(param_1 + 0x1a0))(param_1,*(undefined4 *)(param_1 + 0x194));
      if (__s != (char *)0x0) {
        a_00 = (BIGNUM *)
               SRP_Calc_x(*(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1a4),__s);
        if (a_00 == (BIGNUM *)0x0) {
          a_01 = (BIGNUM *)0x0;
LAB_080cee4a:
          uVar3 = 0xffffffff;
          BN_clear_free(a_01);
          BN_clear_free(a_00);
        }
        else {
          a_01 = (BIGNUM *)
                 SRP_Calc_client_key(*(undefined4 *)(param_1 + 0x1a8),
                                     *(undefined4 *)(param_1 + 0x1b4),
                                     *(undefined4 *)(param_1 + 0x1ac),a_00,
                                     *(undefined4 *)(param_1 + 0x1bc),a);
          if (a_01 == (BIGNUM *)0x0) goto LAB_080cee4a;
          iVar2 = BN_num_bits(a_01);
          iVar1 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar1 = iVar2 + 0xe;
          }
          sVar4 = iVar1 >> 3;
          to = (uchar *)CRYPTO_malloc(sVar4,"tls_srp.c",0x191);
          if (to == (uchar *)0x0) goto LAB_080cee4a;
          BN_bn2bin(a_01,to);
          uVar3 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0xc))
                            (param_1,param_2,to,sVar4);
          OPENSSL_cleanse(to,sVar4);
          CRYPTO_free(to);
          BN_clear_free(a_01);
          BN_clear_free(a_00);
        }
        sVar4 = strlen(__s);
        OPENSSL_cleanse(__s,sVar4);
        CRYPTO_free(__s);
        goto LAB_080cee0d;
      }
    }
  }
  uVar3 = 0xffffffff;
  BN_clear_free((BIGNUM *)0x0);
  BN_clear_free((BIGNUM *)0x0);
LAB_080cee0d:
  BN_clear_free(a);
  return uVar3;
}

