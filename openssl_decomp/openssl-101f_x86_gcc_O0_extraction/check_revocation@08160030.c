
undefined4 check_revocation(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  X509 *a;
  X509_NAME *pXVar3;
  int iVar4;
  _STACK *st;
  int iVar5;
  X509_CRL *a_00;
  int in_GS_OFFSET;
  int local_44;
  int local_40;
  X509_CRL *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  X509_CRL *local_28;
  X509_CRL *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = *(uint *)(*(int *)(param_1 + 0x14) + 0xc);
  if ((uVar1 & 4) != 0) {
    if ((uVar1 & 8) == 0) {
      if (*(int *)(param_1 + 0x7c) != 0) goto LAB_08160060;
      local_40 = 0;
    }
    else {
      local_40 = sk_num(*(_STACK **)(param_1 + 0x54));
      local_40 = local_40 + -1;
      if (local_40 < 0) goto LAB_08160060;
    }
    local_44 = 0;
    do {
      local_38 = (X509_CRL *)0x0;
      *(int *)(param_1 + 0x60) = local_44;
      a = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),local_44);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(X509 **)(param_1 + 0x68) = a;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x78) = 0;
      iVar5 = 0;
      do {
        if (*(code **)(param_1 + 0x30) != (code *)0x0) {
          a_00 = (X509_CRL *)0x0;
          iVar4 = (**(code **)(param_1 + 0x30))(param_1,&local_38,a);
          if (iVar4 != 0) goto LAB_08160101;
LAB_081602c0:
          *(undefined4 *)(param_1 + 100) = 3;
          iVar5 = (**(code **)(param_1 + 0x20))(0,param_1);
          X509_CRL_free(local_38);
          X509_CRL_free((X509_CRL *)0x0);
          *(undefined4 *)(param_1 + 0x70) = 0;
          if (iVar5 != 0) goto LAB_081602fb;
          uVar2 = 0;
          goto LAB_08160065;
        }
        local_34 = 0;
        local_30 = 0;
        local_28 = (X509_CRL *)0x0;
        local_24 = (X509_CRL *)0x0;
        pXVar3 = X509_get_issuer_name(a);
        local_2c = *(undefined4 *)(param_1 + 0x78);
        iVar4 = get_crl_sk(&local_34,&local_30,&local_2c,*(undefined4 *)(param_1 + 0x10));
        if (iVar4 == 0) {
          st = (_STACK *)(**(code **)(param_1 + 0x44))(param_1,pXVar3);
          if ((st != (_STACK *)0x0) || (local_28 == (X509_CRL *)0x0)) {
            get_crl_sk(&local_34,&local_30,&local_2c,st);
            sk_pop_free(st,X509_CRL_free);
            goto joined_r0x081602b2;
          }
        }
        else {
joined_r0x081602b2:
          if (local_28 == (X509_CRL *)0x0) goto LAB_081602c0;
        }
        *(undefined4 *)(param_1 + 0x6c) = local_34;
        *(undefined4 *)(param_1 + 0x74) = local_30;
        *(undefined4 *)(param_1 + 0x78) = local_2c;
        a_00 = local_24;
        local_38 = local_28;
LAB_08160101:
        *(X509_CRL **)(param_1 + 0x70) = local_38;
        iVar4 = (**(code **)(param_1 + 0x34))(param_1,local_38);
        if (iVar4 == 0) {
LAB_08160240:
          X509_CRL_free(local_38);
          X509_CRL_free(a_00);
          *(undefined4 *)(param_1 + 0x70) = 0;
          uVar2 = 0;
          goto LAB_08160065;
        }
        if (a_00 == (X509_CRL *)0x0) {
LAB_0816014b:
          iVar4 = (**(code **)(param_1 + 0x38))(param_1,local_38,a);
          if (iVar4 == 0) goto LAB_08160240;
        }
        else {
          iVar4 = (**(code **)(param_1 + 0x34))(param_1,a_00);
          if ((iVar4 == 0) || (iVar4 = (**(code **)(param_1 + 0x38))(param_1,a_00,a), iVar4 == 0))
          goto LAB_08160240;
          if (iVar4 != 2) goto LAB_0816014b;
        }
        X509_CRL_free(local_38);
        X509_CRL_free(a_00);
        iVar4 = *(int *)(param_1 + 0x78);
        local_38 = (X509_CRL *)0x0;
        if (iVar4 == iVar5) goto LAB_081602c0;
        iVar5 = iVar4;
      } while (iVar4 != 0x807f);
      X509_CRL_free((X509_CRL *)0x0);
      X509_CRL_free((X509_CRL *)0x0);
      *(undefined4 *)(param_1 + 0x70) = 0;
LAB_081602fb:
      local_44 = local_44 + 1;
    } while (local_44 <= local_40);
  }
LAB_08160060:
  uVar2 = 1;
LAB_08160065:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

