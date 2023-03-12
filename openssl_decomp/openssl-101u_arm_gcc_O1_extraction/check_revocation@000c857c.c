
undefined4 check_revocation(int param_1)

{
  X509 *a;
  X509_NAME *pXVar1;
  int iVar2;
  _STACK *st;
  int iVar3;
  int iVar4;
  X509_CRL *pXVar5;
  X509_CRL *a_00;
  int local_44;
  X509_CRL *local_40;
  X509_CRL *local_3c;
  X509_CRL *local_38;
  undefined4 local_34;
  X509_CRL *local_30;
  X509_CRL *local_2c [2];
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x14) + 0xc);
  if (iVar4 << 0x1d < 0) {
    if (iVar4 << 0x1c < 0) {
      local_44 = sk_num(*(_STACK **)(param_1 + 0x54));
      local_44 = local_44 + -1;
      if (local_44 < 0) {
        return 1;
      }
    }
    else {
      local_44 = *(int *)(param_1 + 0x7c);
      if (local_44 != 0) {
        return 1;
      }
    }
    iVar4 = 0;
    do {
      *(int *)(param_1 + 0x60) = iVar4;
      local_40 = (X509_CRL *)0x0;
      a = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar4);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x78) = 0;
      *(X509 **)(param_1 + 0x68) = a;
      iVar3 = 0;
      do {
        pXVar5 = *(X509_CRL **)(param_1 + 0x30);
        if (pXVar5 != (X509_CRL *)0x0) {
          a_00 = (X509_CRL *)0x0;
          iVar2 = (*(code *)pXVar5)(param_1,&local_40,a);
          if (iVar2 != 0) goto LAB_000c85ee;
LAB_000c870a:
          *(undefined4 *)(param_1 + 100) = 3;
          iVar3 = (**(code **)(param_1 + 0x20))(0,param_1);
          X509_CRL_free(local_40);
          X509_CRL_free((X509_CRL *)0x0);
          *(undefined4 *)(param_1 + 0x70) = 0;
          if (iVar3 == 0) {
            return 0;
          }
          goto LAB_000c872e;
        }
        local_3c = pXVar5;
        local_38 = pXVar5;
        local_30 = pXVar5;
        local_2c[0] = pXVar5;
        pXVar1 = X509_get_issuer_name(a);
        local_34 = *(undefined4 *)(param_1 + 0x78);
        iVar2 = get_crl_sk(param_1,&local_30,local_2c,&local_3c,&local_38,&local_34,
                           *(undefined4 *)(param_1 + 0x10));
        if (iVar2 == 0) {
          st = (_STACK *)(**(code **)(param_1 + 0x44))(param_1,pXVar1);
          if ((st != (_STACK *)0x0) || (local_30 == (X509_CRL *)0x0)) {
            get_crl_sk(param_1,&local_30,local_2c,&local_3c,&local_38,&local_34,st);
            sk_pop_free(st,X509_CRL_free);
            goto joined_r0x000c8708;
          }
        }
        else {
joined_r0x000c8708:
          if (local_30 == (X509_CRL *)0x0) goto LAB_000c870a;
        }
        *(X509_CRL **)(param_1 + 0x6c) = local_3c;
        *(X509_CRL **)(param_1 + 0x74) = local_38;
        *(undefined4 *)(param_1 + 0x78) = local_34;
        a_00 = local_2c[0];
        local_40 = local_30;
LAB_000c85ee:
        *(X509_CRL **)(param_1 + 0x70) = local_40;
        iVar2 = (**(code **)(param_1 + 0x34))(param_1);
        if (iVar2 == 0) goto LAB_000c86b4;
        if (a_00 == (X509_CRL *)0x0) {
LAB_000c8628:
          iVar2 = (**(code **)(param_1 + 0x38))(param_1,local_40,a);
          if (iVar2 == 0) {
LAB_000c86b4:
            X509_CRL_free(local_40);
            X509_CRL_free(a_00);
            *(undefined4 *)(param_1 + 0x70) = 0;
            return 0;
          }
        }
        else {
          iVar2 = (**(code **)(param_1 + 0x34))(param_1,a_00);
          if ((iVar2 == 0) || (iVar2 = (**(code **)(param_1 + 0x38))(param_1,a_00,a), iVar2 == 0))
          goto LAB_000c86b4;
          if (iVar2 != 2) goto LAB_000c8628;
        }
        X509_CRL_free(local_40);
        X509_CRL_free(a_00);
        iVar2 = *(int *)(param_1 + 0x78);
        local_40 = (X509_CRL *)0x0;
        if (iVar2 == iVar3) goto LAB_000c870a;
        iVar3 = iVar2;
      } while (iVar2 != 0x807f);
      X509_CRL_free((X509_CRL *)0x0);
      X509_CRL_free((X509_CRL *)0x0);
      *(undefined4 *)(param_1 + 0x70) = 0;
LAB_000c872e:
      iVar4 = iVar4 + 1;
    } while (iVar4 <= local_44);
  }
  return 1;
}

