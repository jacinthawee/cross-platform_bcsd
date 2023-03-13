
int X509_STORE_CTX_get1_issuer(X509 **issuer,X509_STORE_CTX *ctx,X509 *x)

{
  X509_NAME *name;
  int iVar1;
  int *mode;
  int *piVar2;
  X509_NAME *b;
  int in_GS_OFFSET;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *local_34;
  X509_OBJECT local_28;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  name = X509_get_issuer_name(x);
  iVar1 = X509_STORE_get_by_subject(ctx,1,name,&local_28);
  if (iVar1 == 1) {
    iVar1 = (*ctx->check_issued)(ctx,x,(X509 *)local_28.data.ptr);
    if (iVar1 == 0) {
      if (local_28.type == 1) {
        X509_free(local_28.data.x509);
      }
      else if (local_28.type == 2) {
        X509_CRL_free(local_28.data.crl);
      }
      uVar5 = 0x272;
      pcVar4 = "x509_lu.c";
      uVar3 = 0xb;
      CRYPTO_lock(local_28.type,9,(char *)0xb,(int)"x509_lu.c");
      mode = (int *)x509_object_idx_cnt(0,uVar3,pcVar4,uVar5);
      local_34 = mode;
      if (mode != (int *)0xffffffff) {
        while ((mode = (int *)sk_num((_STACK *)ctx->ctx->objs), (int)local_34 < (int)mode &&
               (piVar2 = (int *)sk_value((_STACK *)ctx->ctx->objs,(int)local_34), mode = piVar2,
               *piVar2 == 1))) {
          b = X509_get_subject_name((X509 *)piVar2[1]);
          mode = (int *)X509_NAME_cmp(name,b);
          if (mode != (int *)0x0) break;
          iVar1 = (*ctx->check_issued)(ctx,x,(X509 *)piVar2[1]);
          if (iVar1 != 0) {
            *issuer = (X509 *)piVar2[1];
            mode = (int *)*piVar2;
            if (mode == (int *)0x1) {
              iVar1 = 1;
              mode = (int *)CRYPTO_add_lock((int *)(piVar2[1] + 0x10),1,3,"x509_lu.c",0x18a);
            }
            else if (mode == (int *)0x2) {
              iVar1 = 1;
              mode = (int *)CRYPTO_add_lock((int *)(piVar2[1] + 0xc),1,6,"x509_lu.c",0x18d);
            }
            else {
              iVar1 = 1;
            }
            goto LAB_08164241;
          }
          local_34 = (int *)((int)local_34 + 1);
        }
      }
      iVar1 = 0;
LAB_08164241:
      CRYPTO_lock((int)mode,10,(char *)0xb,(int)"x509_lu.c");
    }
    else {
      *issuer = (X509 *)local_28.data;
      iVar1 = 1;
    }
  }
  else if (iVar1 == -1) {
    if (local_28.type == 1) {
      X509_free(local_28.data.x509);
    }
    else if (local_28.type == 2) {
      X509_CRL_free(local_28.data.crl);
    }
    ERR_put_error(0xb,0x92,0x6a,"x509_lu.c",0x260);
    iVar1 = -1;
  }
  else if (iVar1 == 0) {
    iVar1 = 0;
  }
  else if (local_28.type == 1) {
    X509_free(local_28.data.x509);
    iVar1 = -1;
  }
  else if (local_28.type == 2) {
    X509_CRL_free(local_28.data.crl);
    iVar1 = -1;
  }
  else {
    iVar1 = -1;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

