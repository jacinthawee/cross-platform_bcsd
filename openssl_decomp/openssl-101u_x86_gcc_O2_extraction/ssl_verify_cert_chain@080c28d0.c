
int ssl_verify_cert_chain(void *param_1,_STACK *param_2)

{
  X509_VERIFY_PARAM *from;
  code *pcVar1;
  int iVar2;
  X509 *x509;
  char *name;
  X509_VERIFY_PARAM *to;
  int in_GS_OFFSET;
  X509_STORE_CTX local_98;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 != (_STACK *)0x0) {
    iVar2 = sk_num(param_2);
    if (iVar2 != 0) {
      x509 = (X509 *)sk_value(param_2,0);
      iVar2 = X509_STORE_CTX_init(&local_98,*(X509_STORE **)(*(int *)((int)param_1 + 0xe4) + 0xc),
                                  x509,(stack_st_X509 *)param_2);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xcf,0xb,"ssl_cert.c",0x1dc);
      }
      else {
        iVar2 = SSL_get_ex_data_X509_STORE_CTX_idx();
        X509_STORE_CTX_set_ex_data(&local_98,iVar2,param_1);
        name = "ssl_client";
        if (*(int *)((int)param_1 + 0x24) == 0) {
          name = "ssl_server";
        }
        X509_STORE_CTX_set_default(&local_98,name);
        from = *(X509_VERIFY_PARAM **)((int)param_1 + 0x70);
        to = X509_STORE_CTX_get0_param(&local_98);
        X509_VERIFY_PARAM_set1(to,from);
        if (*(verify_cb **)((int)param_1 + 0xcc) != (verify_cb *)0x0) {
          X509_STORE_CTX_set_verify_cb(&local_98,*(verify_cb **)((int)param_1 + 0xcc));
        }
        pcVar1 = *(code **)(*(int *)((int)param_1 + 0xe4) + 100);
        if (pcVar1 == (code *)0x0) {
          iVar2 = X509_verify_cert(&local_98);
        }
        else {
          iVar2 = (*pcVar1)(&local_98,*(undefined4 *)(*(int *)((int)param_1 + 0xe4) + 0x68));
        }
        *(int *)((int)param_1 + 0xec) = local_98.error;
        X509_STORE_CTX_cleanup(&local_98);
      }
      goto LAB_080c290c;
    }
  }
  iVar2 = 0;
LAB_080c290c:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
