--Task 1
--SELECT * FROM "CATALOGS"

--Task 2
-- если больше ИЛИ равно и меньше ИЛИ равно
-- SELECT * FROM "CATALOGS"
-- WHERE "ID_CATALOG" BETWEEN 2 AND 4

-- если больше ИЛИ равно и меньше ИЛИ равно
-- SELECT * FROM "CATALOGS"
-- WHERE "ID_CATALOG" > 2 AND "ID_CATALOG" < 4


-- Task 3
-- SELECT * FROM "PRODUCTS" WHERE "NAME" ilike '%Celeron%'

-- Task 4
--SELECT * FROM "ORDERS" WHERE "ORDERTIME"::date >= '2023-10-01'::date AND "ORDERTIME"::date < '2023-11-01'

-- Task 5
-- SELECT 
-- 	"USERS".* 
-- FROM "USERS"
-- JOIN "ORDERS" USING("ID_USER")
-- JOIN "PRODUCTS" ON ("ORDERS"."ID_PRODUCT" = "PRODUCTS"."ID_PRODUCT" AND "PRODUCTS"."PRICE" > 1000)
