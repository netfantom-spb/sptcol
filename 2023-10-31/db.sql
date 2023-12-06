CREATE TABLE "public"."suppliers" (
  "supplierId" int4 NOT NULL,
  "supplierName" text COLLATE "pg_catalog"."default",
  "address" text COLLATE "pg_catalog"."default",
  "phone" text COLLATE "pg_catalog"."default",
  CONSTRAINT "suppliers_pkey" PRIMARY KEY ("supplierId")
)
;

ALTER TABLE "public"."suppliers" 
  OWNER TO "postgres";
  
 CREATE TABLE "public"."products" (
  "productId" int4 NOT NULL,
  "productName" text COLLATE "pg_catalog"."default",
  "category" text COLLATE "pg_catalog"."default",
  "price" numeric(6,2),
  CONSTRAINT "products_pkey" PRIMARY KEY ("productId")
)
;

ALTER TABLE "public"."products" 
  OWNER TO "postgres";
  
  
CREATE TABLE "public"."customers" (
  "customerId" int4 NOT NULL,
  "customerName" text COLLATE "pg_catalog"."default",
  "address" text COLLATE "pg_catalog"."default",
  "phone" text COLLATE "pg_catalog"."default",
  CONSTRAINT "customers_pkey" PRIMARY KEY ("customerId")
)
;

ALTER TABLE "public"."customers" 
  OWNER TO "postgres";
  
  
CREATE TABLE "public"."orders" (
  "orderId" int4 NOT NULL,
  "createdAt" date,
  "customerId" int4,
  "productId" int4,
  "quantity" int2,
  CONSTRAINT "orders_pkey" PRIMARY KEY ("orderId"),
  CONSTRAINT "orders_customerId_fkey" FOREIGN KEY ("customerId") REFERENCES "public"."customers" ("customerId") ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT "orders_productId_fkey" FOREIGN KEY ("productId") REFERENCES "public"."products" ("productId") ON DELETE RESTRICT ON UPDATE CASCADE
)
;

ALTER TABLE "public"."orders" 
  OWNER TO "postgres";
  
  
CREATE TABLE "public"."payments" (
  "paymentId" int4 NOT NULL,
  "orderId" int4,
  "amount" numeric(11,2),
  "createdAt" date,
  CONSTRAINT "payments_pkey" PRIMARY KEY ("paymentId"),
  CONSTRAINT "payments_orderId_fkey" FOREIGN KEY ("orderId") REFERENCES "public"."orders" ("orderId") ON DELETE CASCADE ON UPDATE CASCADE
)
;

ALTER TABLE "public"."payments" 
  OWNER TO "postgres";