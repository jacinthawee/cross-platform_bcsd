
X509_EXTENSION * OCSP_accept_responses_new(char **oids)

{
  _STACK *st;
  int n;
  ASN1_OBJECT *data;
  X509_EXTENSION *pXVar1;
  
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    pXVar1 = (X509_EXTENSION *)0x0;
  }
  else {
    if (oids != (char **)0x0) {
      do {
        while( true ) {
          if (*oids == (char *)0x0) goto LAB_081847b0;
          n = OBJ_txt2nid(*oids);
          if ((n != 0) && (data = OBJ_nid2obj(n), data != (ASN1_OBJECT *)0x0)) break;
          oids = oids + 1;
          if (oids == (char **)0x0) goto LAB_081847b0;
        }
        sk_push(st,data);
        oids = oids + 1;
      } while (oids != (char **)0x0);
    }
LAB_081847b0:
    pXVar1 = X509V3_EXT_i2d(0x170,0,st);
    sk_pop_free(st,ASN1_OBJECT_free);
  }
  return pXVar1;
}

