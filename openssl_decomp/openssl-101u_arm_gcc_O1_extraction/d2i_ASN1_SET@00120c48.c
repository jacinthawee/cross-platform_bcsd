
stack_st_OPENSSL_BLOCK *
d2i_ASN1_SET(stack_st_OPENSSL_BLOCK **a,uchar **pp,long length,undefined1 *d2i,free_func *free_func,
            int ex_tag,int ex_class)

{
  void *data;
  int iVar1;
  _STACK *st;
  uchar *local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  uchar *local_34;
  uchar *local_30;
  
  if (((a == (stack_st_OPENSSL_BLOCK **)0x0) || (st = (_STACK *)*a, st == (_STACK *)0x0)) &&
     (st = sk_new_null(), st == (_STACK *)0x0)) {
    ERR_put_error(0xd,0x94,0x41,"a_set.c",0xb4);
  }
  else {
    local_4c = *pp;
    local_30 = local_4c + length;
    if (length == 0) {
      local_30 = (uchar *)length;
    }
    local_40 = ASN1_get_object(&local_4c,(long *)&local_34,&local_3c,&local_38,
                               (int)local_30 - (int)local_4c);
    if (-1 < local_40 << 0x18) {
      if (local_38 == ex_class) {
        if (local_3c == ex_tag) {
          if (local_30 < local_4c + (int)local_34) {
            ERR_put_error(0xd,0x94,0x88,"a_set.c",0xc9);
          }
          else {
            local_30 = local_4c + (int)local_34;
            if (local_40 == 0x21) {
              local_34 = *pp + (length - (int)local_4c);
              local_30 = local_4c + (int)local_34;
            }
            do {
              if (local_30 <= local_4c) {
LAB_00120d84:
                if (a != (stack_st_OPENSSL_BLOCK **)0x0) {
                  *a = (stack_st_OPENSSL_BLOCK *)st;
                }
                *pp = local_4c;
                return (stack_st_OPENSSL_BLOCK *)st;
              }
              if (local_40 << 0x1f < 0) {
                local_48 = ASN1_const_check_infinite_end(&local_4c,(long)local_34);
                iVar1 = local_48;
                if (local_48 != 0) {
                  iVar1 = 1;
                }
              }
              else if ((int)local_34 < 1) {
                iVar1 = 1;
              }
              else {
                iVar1 = 0;
              }
              if (iVar1 != 0) goto LAB_00120d84;
              data = (void *)(*(code *)d2i)(0,&local_4c,local_34);
              if (data == (void *)0x0) {
                ERR_put_error(0xd,0x94,0x71,"a_set.c",0xde);
                asn1_add_error(*pp,(int)local_4c - (int)*pp);
                break;
              }
              iVar1 = sk_push(st,data);
            } while (iVar1 != 0);
          }
        }
        else {
          ERR_put_error(0xd,0x94,0x68,"a_set.c",0xc5);
        }
      }
      else {
        ERR_put_error(0xd,0x94,0x65,"a_set.c",0xc1);
      }
    }
    if ((a == (stack_st_OPENSSL_BLOCK **)0x0) || (st != (_STACK *)*a)) {
      if (free_func == (free_func *)0x0) {
        sk_free(st);
        return (stack_st_OPENSSL_BLOCK *)0x0;
      }
      sk_pop_free(st,(func *)free_func);
      st = (_STACK *)0x0;
    }
    else {
      st = (_STACK *)0x0;
    }
  }
  return (stack_st_OPENSSL_BLOCK *)st;
}

