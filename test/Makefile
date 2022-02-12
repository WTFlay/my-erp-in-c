TEST = product

test:
	for test in ${TEST}; do \
		(cd $$test && make) \
	done

clean:
	for test in ${TEST}; do \
		(cd $$test && make clean) \
	done


.PHONY: test clean