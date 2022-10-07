// case from Hackerank
// Name : Teddy Firman
// Github ID : TeddyFirman
---------------------------------------

package parity

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"sync"
)

/*
 * Complete the 'Server' function below and missing types and global variables.
 *
 * The function is void.
 */
type in struct {
	value    int32
	oddChan  chan int32
	evenChan chan int32
}

var serverChan chan in

func Server() {
	for v := range serverChan {
		if v.value%2 == 0 {
			v.evenChan <- v.value
		} else {
			v.oddChan <- v.value
		}
	}
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 16*1024*1024)

	stdout, err := os.Create(os.Getenv("OUTPUT_PATH"))
	checkError(err)

	defer stdout.Close()

	writer := bufio.NewWriterSize(stdout, 16*1024*1024)

	arrCount, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	checkError(err)

	var arr []int32

	for i := 0; i < int(arrCount); i++ {
		arrItemTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
		checkError(err)
		arrItem := int32(arrItemTemp)
		arr = append(arr, arrItem)
	}

	oddChan := make(chan int32)
	evenChan := make(chan int32)
	serverChan = make(chan in, len(arr))
	for idx := 0; idx < len(arr); idx++ {
		i := idx
		serverChan <- in{arr[i], oddChan, evenChan}
	}
	odds, evens := []int32{}, []int32{}
	wg := &sync.WaitGroup{}
	wg.Add(len(arr))
	go func() {
		for newOdd := range oddChan {
			odds = append(odds, newOdd)
			wg.Done()
		}
	}()
	go func() {
		for newEven := range evenChan {
			evens = append(evens, newEven)
			wg.Done()
		}
	}()
	go Server()
	wg.Wait()

	for _, resultItem := range odds {
		fmt.Fprintf(writer, "%d", resultItem)
		fmt.Fprintf(writer, "\n")
	}

	for i, resultItem := range evens {
		fmt.Fprintf(writer, "%d", resultItem)

		if i != len(evens)-1 {
			fmt.Fprintf(writer, "\n")
		}
	}

	fmt.Fprintf(writer, "\n")

	writer.Flush()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err != nil {
		panic(err)
	}
}


*//////////////////////////////////////////////////////*
