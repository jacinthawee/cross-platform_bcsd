
X509_EXTENSION * X509_REVOKED_get_ext(X509_REVOKED *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = X509v3_get_ext(x->extensions,loc);
  return pXVar1;
}
